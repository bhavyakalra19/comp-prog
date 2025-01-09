class Node{
    public:
        char data;
        unordered_map<char, Node*> mp;
        unordered_map<int,int> check;
        Node(char a){
            data = a;
        }
};

class Trie{
    public:
        Node *root;
        Trie(){
            root = new Node('\0');
        }

        void insert(string word, int idx){
            Node *temp = root;
            for(auto s : word){
                if(temp->mp.find(s) == temp->mp.end()){
                    Node *t = new Node(s);
                    temp->mp[s] = t;
                }
                temp = temp->mp[s];
                temp->check[idx] = 1;
            }
        }

        void insertBack(string word, int idx, int z){
            int n = word.size();
            Node *temp = root;
            for(int i = n-1; i >= 0; i--){
                if(temp->mp.find(word[i]) == temp->mp.end()){
                    Node *t = new Node(word[i]);
                    temp->mp[word[i]] = t;
                }
                temp = temp->mp[word[i]];
                temp->check[idx + z] = 1;
            }
        }

        long long search(string word, int z){
            Node *temp = root;
            Node *back = root;
            for(auto a : word){
                if(temp->mp.find(a) == temp->mp.end()){
                    return 0;
                }
                temp = temp->mp[a];
            }
            int n = word.size();
            for(int i = n - 1; i >= 0; i--){
                if(back->mp.find(word[i]) == back->mp.end()){
                    return 0;
                }
                back = back->mp[word[i]];
            }
            int ans = 0;
            for(auto m : temp->check){
                if(back->check.find(m.first + z) != back->check.end()){
                    ans++;
                }
            }
            return ans;
        }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        Trie *t = new Trie();
        int n = words.size();
        long long ans = 0;
        for(int i = n-1; i >= 0; i--){
            ans += t->search(words[i],n);
            t->insert(words[i],i);
            t->insertBack(words[i],i,n);
        }
        return ans;
    }
};