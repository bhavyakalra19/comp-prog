class Node{
    public:
        char data;
        unordered_map<char,Node*> mp;
        int count;

        Node(char c){
            data = c;
            count = 0;
        }
};

class Trie{
    public:
        Node *root;

        Trie(){
            root = new Node('\0');
        }

        void insert(string word){
            Node *temp = root;
            for(int i = 0; i < word.size(); i++){
                if(temp->mp.find(word[i]) == temp->mp.end()){
                    temp->mp[word[i]] = new Node(word[i]);
                }
                temp = temp->mp[word[i]];
                temp->count += 1;
            }
        }

        int search(string word){
            Node *temp = root;
            int ans = 0;
            for(int i = 0; i < word.size(); i++){
                if(temp->mp.find(word[i]) == temp->mp.end()){
                    return ans;
                }
                temp = temp->mp[word[i]];
                ans += temp->count;
            }
            return ans;
        }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> ans;
        Trie t;
        for(int i = 0; i < n; i++){
            t.insert(words[i]);
        }

        for(int i = 0; i < n; i++){
            ans.push_back(t.search(words[i]));
        }
        return ans;
    }
};