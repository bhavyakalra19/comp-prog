class Node{
    public:
        string data;
        unordered_map<string, Node*> mp;

        Node(string d){
            data = d;
        }
};



class Trie{
    unordered_map<string, Node*> string_map;
    unordered_map<Node*, bool> check_map;
    public:
        Node *root;
        
        Trie(){
            root = new Node("");
        }

        void addNode(vector<string> path){
            Node *temp = root;
            for(auto a : path){
                if(temp->mp.find(a) == temp->mp.end()){
                    temp->mp[a] = new Node(a);
                }
                temp = temp->mp[a];
            }
        }

        vector<string> dfs(Node *temp){
            vector<string> ans;
            for(auto a : temp->mp){
                vector<string> arr;
                arr = dfs(temp->mp[a.first]);
                for(auto s : arr){
                    ans.push_back(s);
                }
            }

            if(ans.size() == 0){
                ans.push_back(temp->data);
            }else{
                string s = "";
                sort(ans.begin(), ans.end());
                for(auto a : ans){
                    s += a;
                    s += "-";
                }
                if(string_map.find(s) == string_map.end()){
                    string_map[s] = temp;
                }else{
                    check_map[temp] = true;
                    check_map[string_map[s]] = true;
                }
                for(int i = 0; i < ans.size(); i++){
                    ans[i] = temp->data + ans[i];
                }
            }
            return ans;
        }

        void getAns(Node *temp, vector<vector<string>> &ans, vector<string> s){
            if(check_map[temp]){
                return;
            }
            s.push_back(temp->data);
            ans.push_back(s);
            for(auto a : temp->mp){
                getAns(temp->mp[a.first], ans, s);
            }
        }
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie *t = new Trie();
        for(auto &path : paths){
            t->addNode(path);
        }
        t->dfs(t->root);
        vector<vector<string>> ans;
        vector<string> s;
        for(auto a : t->root->mp){
            t->getAns(t->root->mp[a.first], ans, s);
        }
        return ans;
    }
};