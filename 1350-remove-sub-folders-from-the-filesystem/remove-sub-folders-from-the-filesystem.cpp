class Node{
    public:
        string data;
        unordered_map<string, Node*> mp;
        bool end;
        Node(string d){
            data = d;
            end = false;
        }
};

class Trie{
    public:
        Node *root;

        Trie(){
            root = new Node(" ");
        }

        bool addNode(string s){
            Node *temp = root;
            int n = s.size();
            vector<string> ans;
            int i = 0;
            while(i < n){
                string check = "";
                while(i < n && s[i] == '/'){
                    i++;
                }
                while(i < n && s[i] != '/'){
                    check += s[i++];
                }
                ans.push_back(check);
            }
            for(auto a : ans){
                if(temp->mp.find(a) == temp->mp.end()){
                    temp->mp[a] = new Node(a);
                }
                temp = temp->mp[a];
                if(temp->end == true){
                    return false;
                }
            }
            temp->end = true;
            return true;
        }
};


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        Trie *t = new Trie();
        sort(folder.begin(), folder.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });
        for(auto f : folder){
            if(t->addNode(f)){
                ans.push_back(f);
            }
        }
        return ans;
    }
};