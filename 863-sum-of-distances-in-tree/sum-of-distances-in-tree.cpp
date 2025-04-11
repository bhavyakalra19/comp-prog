class Solution {
public:
    void dfs1(vector<vector<int>> &adj, int idx, int par, vector<int> &check, vector<int> &res){
        for(auto &a : adj[idx]){
            if(a != par){
                dfs1(adj, a, idx, check, res);
                check[idx] += check[a];
                res[idx] += res[a] + check[a];
            }
        }
    }
    
    void dfs2(vector<vector<int>> &adj, int idx, int par, vector<int> &check, vector<int> &res){
        res[idx] = res[par] - check[idx] + adj.size() - check[idx];
        for(auto &a : adj[idx]){
            if(par != a){
                dfs2(adj, a, idx, check, res);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> check(n,1);
        vector<int> res(n,0);
        dfs1(adj, 0, -1, check, res);
        for(auto &a : adj[0]){
            dfs2(adj, a, 0, check, res);
        }
        return res;
    }
};