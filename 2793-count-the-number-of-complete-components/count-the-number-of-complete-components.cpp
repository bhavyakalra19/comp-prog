class Solution {
public:

    void checkGraph(int node, vector<int> &check, vector<vector<int>> &graph, vector<bool> &vis){
        vis[node] = true;
        check.push_back(graph[node].size());

        for(auto &a : graph[node]){
            if(!vis[a]){
                checkGraph(a, check, graph, vis);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> graph(n);
        for(auto &a : edges){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }

        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++){
            if(graph[i].size() == 0){
                ans++;
            }else if(!vis[i]){
                vector<int> check;
                checkGraph(i, check, graph, vis);

                if(check.size() - 1 != check[0]){
                    continue;
                }
                
                bool correct = true;
                for(int i = 1; i < check.size(); i++){
                    if(check[i] != check[i-1]){
                        correct = false;
                        break;
                    }
                }
                if(correct){
                    ans++;
                }
            }
        }
        return ans;
    }
};