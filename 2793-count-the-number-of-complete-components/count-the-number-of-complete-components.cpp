class Solution {
public:
    void getAns(vector<vector<int>> &adj, int &v, int &e, vector<bool> &check, int idx){
        check[idx] = true;
        e++;
        for(auto &a : adj[idx]){
            v++;
            if(!check[a]){
                getAns(adj, v, e, check, a);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> check(n,false);
        vector<vector<int>> adj(n);
        int cnt = 0;
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i = 0; i < n; i++){
            if(!check[i]){
                int v = 0;
                int e = 0;
                getAns(adj, v, e, check, i);
                if(((e * (e - 1)) == v) || e == 1) cnt++;
            }
        }
        return cnt;
    }
};