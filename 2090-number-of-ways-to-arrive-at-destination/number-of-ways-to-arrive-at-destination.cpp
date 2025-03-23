class Solution {
public:
    const int mod = 1e9 + 7;
    int getAns(vector<vector<pair<int,int>>> &adj, int n){
        vector<long long> check(n,LONG_MAX);
        check[0] = 0;
        vector<int> ans(n,0);
        ans[0] = 1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cx = it.second;
            long long cw = it.first;
            if(cw > check[cx]) continue;
            for(auto &a : adj[cx]){
                long long nw = cw + 1LL * a.second;
                if(nw < check[a.first]){
                    check[a.first] = nw;
                    ans[a.first] = ans[cx];
                    pq.push({nw, a.first});
                }else if(nw == check[a.first]){
                    ans[a.first] = (ans[a.first] + ans[cx]) % mod;
                }
            }
        }
        return ans[n-1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &r : roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }
        int a = getAns(adj, n);
        return a;
    }
};