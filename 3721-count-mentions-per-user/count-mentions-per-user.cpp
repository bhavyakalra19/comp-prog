class Solution {
public:
    vector<int> getUsers(string s){
        vector<int> users;
        string u = "";
        for(auto as : s){ 
            if(as == ' '){
                users.push_back(stoi(u));
                u = "";
            }
            if(as != 'i' && as != 'd' && as != ' '){
                u += as;
            }
        }
        users.push_back(stoi(u));
        return users;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;
        vector<int> ans(n,0);
        vector<int> online(n,0);
        sort(events.begin(), events.end(), [](const vector<string> &a, const vector<string> &b){
            if(a[1] == b[1]){
                return a[0] > b[0];
            }
            return stoi(a[1]) < stoi(b[1]);
        });
        for(auto e : events){
            if(e[0] == "MESSAGE"){
                //message
                int t = stoi(e[1]);
                if(e[2] == "HERE"){
                    for(int i = 0; i < n; i++){
                        if(online[i] <= t){
                            ans[i] += 1;
                        }
                    }
                }else if(e[2] == "ALL"){
                    for(int i = 0; i < n; i++){
                        ans[i] += 1;
                    }
                }else{
                    vector<int> users = getUsers(e[2]);
                    for(auto u : users){
                        ans[u] += 1;
                    }
                }
            }else{
                //offline
                int u = stoi(e[2]);
                int t = stoi(e[1]);
                online[u] = t + 60;
            }
        }
        return ans;
    }
};