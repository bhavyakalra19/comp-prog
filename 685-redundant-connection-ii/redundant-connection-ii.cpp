class Solution {
public:

    void getAns(vector<vector<int>> &gp ,int idx, int &st, int &en, vector<int> &vis, int &cn){
        vis[idx] = true;
        cn++;
        for(auto g : gp[idx]){
            if((vis[g]) || (idx == st && g == en)){
                continue;
            }
            getAns(gp,g,st,en,vis,cn);
        }
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> gp(n+1);
        vector<int> degree(n+1,0);
        for(auto e : edges){
            gp[e[0]].push_back(e[1]);
            degree[e[1]]++;
        }
        int cn = 0;
        for(int i = 1; i <= n; i++){
            if(degree[i] == 0){
                cn = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            vector<int> vis(n+1,false);
            int cnt = 0;
            if(cn != 0){
                getAns(gp,cn,edges[i][0],edges[i][1],vis,cnt);
            }else if(degree[edges[i][1]] == 1){
                getAns(gp,edges[i][1],edges[i][0],edges[i][1],vis, cnt);
            }
            if(cnt == n){
                return edges[i];
            }
        }
        return {0,0};
    }
};