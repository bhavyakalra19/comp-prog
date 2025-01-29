class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> s1(n,false);
        vector<bool> s2(n,false);
        queue<int> q1;
        queue<int> q2;
        vector<bool> vis(n,false);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                q1.push(i);
            }
            while(!q1.empty() || !q2.empty()){
                while(!q1.empty()){
                    auto it = q1.front();
                    q1.pop();
                    for(auto a : graph[it]){
                        if(s1[a]){
                            return false;
                        }
                        s2[a] = true;
                        if(!vis[a]){
                            vis[a] = true;
                            q2.push(a);
                        }
                    }
                }
                while(!q2.empty()){
                    auto it = q2.front();
                    q2.pop();
                    for(auto a : graph[it]){
                        if(s2[a]){
                            return false;
                        }
                        s1[a] = true;
                        if(!vis[a]){
                            vis[a] = true;
                            q1.push(a);
                        }
                    }
                }
            }
        }
        return true;
    }
};