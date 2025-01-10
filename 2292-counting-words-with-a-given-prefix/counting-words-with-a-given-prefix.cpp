class Node{
    public:
        char data;
        unordered_map<char,Node*> mp;
        int count;
        Node(char a){
            data = a;
            count = 0;
        }
};

class Trie{
    public:
        Node *root;

        Trie(){
            root = new Node('\0');
        }

        void insert(string word, int n){
            Node *temp = root;
            n = min((int)(word.size()),n);
            for(int i = 0; i < n; i++){
                if(temp->mp.find(word[i]) == temp->mp.end()){
                    Node *t = new Node(word[i]);
                    temp->mp[word[i]] = t; 
                }
                temp = temp->mp[word[i]];
                temp->count++;
            }
        }

        int search(string word){
            Node *temp = root;
            for(auto a : word){
                if(temp->mp.find(a) == temp->mp.end()){
                    return 0;
                }
                temp = temp->mp[a];
            }
            return temp->count;
        }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie *t = new Trie();
        int c = pref.size();
        for(auto w : words){
            t->insert(w,c);
        }
        return t->search(pref);
    }
};