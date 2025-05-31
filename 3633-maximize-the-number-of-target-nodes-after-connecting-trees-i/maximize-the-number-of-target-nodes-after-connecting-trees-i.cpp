class Solution {
public:
    void createGraph(vector<vector<int>> &edges, vector<vector<int>> &adj){
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
    }

    int dfs(vector<vector<int>> &adj, int par, int curr, int k){
        if(k == 0) return 1;
        int a = 1;
        for(auto &c : adj[curr]){
            if(c != par){
                a += dfs(adj, curr, c, k-1);
            }
        }
        return a;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);
        createGraph(edges1, adj1);
        createGraph(edges2, adj2);
        vector<int> ans;
        int mx = 0;
        if(k > 0){
            for(int i = 0; i < m; i++){
                mx = max(mx, dfs(adj2, i, i, k-1));
            }
        }
        for(int i = 0; i < n; i++){
            ans.push_back(dfs(adj1, i, i, k) + mx);
        }
        return ans;
    }
};