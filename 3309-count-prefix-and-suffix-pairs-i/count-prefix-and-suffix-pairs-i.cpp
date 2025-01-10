class Node{
    public:
        string data;
        unordered_map<int, Node*> mp;
        int count;

        Node(int ch){
            data = ch;
            count = 0;
        }
};

class Trie{
    public:
        Node *root;

        Trie(){
            root = new Node(0);
        }

        void insert(string word){
            int n = word.size();
            Node *temp = root;
            for(int i = 0; i < n; i++){
                int check = word[i] * 100 + word[n-1-i];
                if(temp->mp.find(check) == temp->mp.end()){
                    Node *t = new Node(check);
                    temp->mp[check] = t;
                }
                temp = temp->mp[check];
                temp->count++;
            }
        }

        long long search(string word){
            int n = word.size();
            Node *temp = root;
            for(int i = 0; i < n; i++){
                int check = word[i] * 100 + word[n-1-i];
                if(temp->mp.find(check) == temp->mp.end()){
                    return 0;
                }
                temp = temp->mp[check];
            }
            return temp->count;
        }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        Trie *t = new Trie();
        int n = words.size();
        long long ans = 0;
        for(int i = n-1; i >= 0; i--){
            ans += t->search(words[i]);
            t->insert(words[i]);
        }
        return ans;
    }
};