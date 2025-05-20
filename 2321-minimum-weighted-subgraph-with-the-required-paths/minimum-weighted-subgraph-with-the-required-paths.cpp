class Solution {
public:
    void getAns(vector<vector<pair<int,int>>> &adj, int src1, int &n, vector<long long> &check){
        check[src1] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, src1});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            long long wt = it.first;
            if(check[node] != wt) continue;
            for(auto &a : adj[node]){
                if(wt + a.second < check[a.first]){
                    check[a.first] = wt + a.second;
                    pq.push({check[a.first], a.first});
                }
            }
        }
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        n = edges.size();
        if(n == 0) return -1;
        vector<vector<pair<int,int>>> adj(n+1);
        vector<vector<pair<int,int>>> adj1(n+1);
        for(auto &e :edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj1[e[1]].push_back({e[0], e[2]});
        }
        vector<long long> a(n+1, LONG_MAX);
        vector<long long> b(n+1, LONG_MAX);
        vector<long long> c(n+1, LONG_MAX);
        getAns(adj, src1, n, a);
        getAns(adj, src2, n, b);
        getAns(adj1, dest, n, c);
        long long ans = LONG_MAX;
        if(c[src1] == LONG_MAX || c[src2] == LONG_MAX) return -1;
        for(int i = 0; i < n; i++){
            if(a[i] != LONG_MAX && b[i] != LONG_MAX && c[i] != LONG_MAX){
                ans = min(ans, a[i] + b[i] + c[i]);
            }
        }
        return ans == LONG_MAX ? -1 : ans;
    }
};