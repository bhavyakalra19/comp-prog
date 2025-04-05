class Solution {
public:
    vector<int> count;
    vector<int> res;
    int n;
    void dfs1(vector<vector<int>> &gp, int par, int idx){
        for(auto &a : gp[idx]){
            if(a != par){
                dfs1(gp, idx, a);
                count[idx] += count[a];
                res[idx] += res[a] + count[a];
            }
        }
    }

    void dfs2(vector<vector<int>> &gp, int par, int idx){
        res[idx] = res[par] - count[idx] + n - count[idx];
        for(auto &a : gp[idx]){
            if(par != a){
                dfs2(gp, idx, a);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        count.resize(n,1);
        res.resize(n,0);
        vector<vector<int>> gp(n);
        for(int i = 0; i < n - 1; i++){
            gp[edges[i][0]].push_back(edges[i][1]);
            gp[edges[i][1]].push_back(edges[i][0]);
        }
        dfs1(gp, -1, 0);
        for(auto &a : gp[0]){
            dfs2(gp, 0, a);
        }
        return res;
    }
};