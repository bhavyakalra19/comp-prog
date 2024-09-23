class Node{
    public:
        char data;
        unordered_map<char,Node*> mp;
        bool terminal;

        Node(char data){
            this->data = data;
            terminal = false;
        }
};

class Trie{
    public:
        Node *root;

        Trie(){
            root = new Node('\0');
        }

        void insert(string s){
            Node *temp = root;
            for(auto a : s){
                if(temp->mp.find(a) == temp->mp.end()){
                    Node *t = new Node(a);
                    temp->mp[a] = t;
                }
                temp = temp->mp[a];
            }
            temp->terminal = true;
        }

        vector<int> search(string s){
            Node *temp = root;
            vector<int> ans;
            for(int i = 0; i < s.size(); i++){
                if(temp->mp.find(s[i]) == temp->mp.end()){
                    break;
                }
                temp = temp->mp[s[i]];
                if(temp->terminal){
                    ans.push_back(i+1);
                }
            }
            return ans;
        }
};

class Solution {
public:
    int n;
    int getAns(string s, int idx, vector<int> &dp, Trie t){
        if(idx == n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }

        vector<int> check = t.search(s.substr(idx));
        if(check.size() == 0){
            return dp[idx] = 1 + getAns(s,idx + 1,dp,t);
        }
        int i = 0;
        int ans;
        if(check[0] == 1){
            i = 1;
            ans = getAns(s,idx + 1,dp,t);
        }else{
            ans = 1 + getAns(s,idx + 1, dp, t);
        }

        for(; i < check.size(); i++){
            ans = min(ans,getAns(s,idx + check[i], dp,t));
        }
        return dp[idx] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        Trie t;
        n = s.size();
        for(int i = 0; i < dictionary.size(); i++){
            t.insert(dictionary[i]);
        }
        vector<int> dp(n,-1);
        return getAns(s,0,dp,t);
    }
};