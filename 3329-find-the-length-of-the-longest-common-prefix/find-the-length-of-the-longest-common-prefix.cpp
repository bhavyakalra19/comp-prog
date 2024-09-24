class Node{
    public:
        char data;
        unordered_map<char,Node*> mp;
        
        Node(char v){
            data = v;
        }
};

class Trie{
    public:
        Node *root;

        Trie(){
            root = new Node('\0');
        }

        void insert(int v){
            string ans = to_string(v);
            Node *temp = root;
            for(int i = 0; i < ans.size(); i++){
                if(temp->mp.find(ans[i]) == temp->mp.end()){
                    temp->mp[ans[i]] = new Node(ans[i]);
                }
                temp = temp->mp[ans[i]];
            }
        }

        int search(int v){
            string ans = to_string(v);
            int a = 0;
            Node *temp = root;
            for(int i = 0; i < ans.size(); i++){
                if(temp->mp.find(ans[i]) == temp->mp.end()){
                    return a;
                }
                a++;
                temp = temp->mp[ans[i]];
            }
            return a;
        }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        for(int i = 0; i < arr2.size(); i++){
            t.insert(arr2[i]);
        }
        int ans = 0;
        for(int i = 0; i < arr1.size(); i++){
            ans = max(ans, t.search(arr1[i]));
        }
        return ans;
    }
};