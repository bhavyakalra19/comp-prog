class Node{
    public:
        char data;
        unordered_map<char,Node*> mp;
        bool isTerminal;
        int count;

        Node(char c){
            data = c;
            isTerminal = false;
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
                    Node *n = new Node(word[i]);
                    temp->mp[word[i]] = n;
                }
                temp = temp->mp[word[i]];
            }
            temp->isTerminal = true;
            temp->count += 1;
        }

        int search(string word){
            Node *temp = root;
            for(int i = 0; i < word.size(); i++){
                if(!temp || (temp->mp).find(word[i]) == (temp->mp).end()){
                    return 0;
                }
                temp = temp->mp[word[i]];
            }
            if(!temp->isTerminal){
                return 0;
            }
            return temp->count;
        }
};

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        Trie t;
        int check = 0;
        unordered_map<string,int> mp;
        for(int i = 0; i < message.size(); i++){
            t.insert(message[i]);
        }
        for(int i = 0; i < bannedWords.size(); i++){
            mp[bannedWords[i]] += 1;
            if(mp[bannedWords[i]] == 1){
                int a = t.search(bannedWords[i]);
                cout << a << endl;
                check += a;
                if(check > 1){
                    return true;
                }
            }
        }
        return false;
    }
};