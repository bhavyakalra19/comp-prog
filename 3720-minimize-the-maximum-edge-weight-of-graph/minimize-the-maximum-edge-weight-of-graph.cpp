class Solution {
public:
    int dfs(vector<vector<pair<int,int>>> &check, int idx, vector<bool> &vis, int m){
        vis[idx] = true;
        int res = 1;
        for(auto [a, b] : check[idx]){
            if(!vis[a] && b <= m){
                res += dfs(check,a,vis,m);
            }
        }
        return res;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>> check(n);
        for(auto e : edges){
            check[e[1]].push_back({e[0], e[2]});
        }

        int l = 1;
        int r = 1000001;
        while(l < r){
            int m = (l + r)/2;
            vector<bool> vis(n,false);
            if(dfs(check,0,vis,m) == n){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return r == 1000001 ? -1 : r;
    }
};