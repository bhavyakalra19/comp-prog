class Node{
    public:
        char data;
        unordered_map<char, Node*> mp;
        vector<int> check;

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
                temp->check.push_back(idx);
            }
        }

        vector<int> search(string word){
            Node *temp = root;
            for(auto a : word){
                if(temp->mp.find(a) == temp->mp.end()){
                    return {};
                }
                temp = temp->mp[a];
            }
            return temp->check;
        }
};

class BackTrie{
    public:
        Node *root;
        BackTrie(){
            root = new Node('\0');
        }

        void insert(string word, int idx){
            reverse(word.begin(), word.end());
            Node *temp = root;
            for(auto s : word){
                if(temp->mp.find(s) == temp->mp.end()){
                    Node *t = new Node(s);
                    temp->mp[s] = t;
                }
                temp = temp->mp[s];
                temp->check.push_back(idx);
            }
        }

        vector<int> search(string word){
            reverse(word.begin(), word.end());
            Node *temp = root;
            for(auto a : word){
                if(temp->mp.find(a) == temp->mp.end()){
                    return {};
                }
                temp = temp->mp[a];
            }
            return temp->check;
        }
};

int getAns(vector<int> check1, vector<int> check2){
    int i = check1.size() - 1;
    int j = check2.size() - 1;
    cout << i << " " << j << endl;
    if(i == 1){
        cout << check1[0] << endl; 
        if(j == 0){
            cout << check2[0] << endl;
        }
    }
    int ans = 0;
    while(i >= 0 && j >= 0){
        if(check1[i] == check2[j]){
            ans++;
            i--;
            j--;
        }else if(check1[i] < check2[j]){
            i--;
        }else{
            j--;
        }
    }
    return ans;
}

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        Trie *t = new Trie();
        BackTrie *b = new BackTrie();
        int n = words.size();
        int ans = 0;
        for(int i = n-1; i >= 0; i--){
            ans += getAns(t->search(words[i]), b->search(words[i]));
            t->insert(words[i],i);
            b->insert(words[i],i);
        }
        return ans;
    }
};