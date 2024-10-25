class Node{
public:
    string data;
    unordered_map<string,Node*> mp;
    bool isTerm;
    Node(string val){
        isTerm = false;
        data = val;
    }
};

class Trie{
public:
    Node *root;

    Trie(){
        root = new Node("start");
    }

    void search(vector<string> str){
        Node *temp = root;
        for(auto s : str){
            if(temp->mp.find(s) == temp->mp.end()){
                temp->mp[s] = new Node(s);
            }
            temp = temp->mp[s];
            if(temp->isTerm){
                return;
            }
        }
        temp->isTerm = true;
    }

    void getAns(Node *root, vector<string> &ans, string s){
        if(root->isTerm){
            ans.push_back(s);
            return;
        }
        for(auto ch : root->mp){
            getAns(ch.second, ans, s + '/' + ch.first);
        }
    } 

    vector<string> check(){
        vector<string> ans;
        getAns(root,ans,"");
        return ans;
    } 
};

class Solution {
public:
    vector<string> getAns(string str){
        vector<string> ans;
        string check;
        for(auto s : str){
            if(s == '/'){
                if(check != ""){
                    ans.push_back(check);
                }
                check = "";
            }else{
                check += s;
            }
        }
        ans.push_back(check);
        return ans;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        Trie t;
        for(auto f : folder){
            t.search(getAns(f));
        }
        return t.check();
    }
};