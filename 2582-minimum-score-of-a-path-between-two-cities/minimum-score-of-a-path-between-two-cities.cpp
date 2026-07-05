class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n + 1);
        for(auto &a : roads){
            graph[a[0]].push_back({a[1], a[2]});
            graph[a[1]].push_back({a[0], a[2]});
        }

        vector<int> check(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({INT_MAX, 1});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int cx = it.second;
            int cw = it.first;

            if(check[cx] != cw) continue;

            for(auto &a : graph[cx]){
                int nx = a.first;
                int nw = min(cw, a.second);

                if(check[nx] > nw){
                    check[nx] = nw;
                    pq.push({nw, nx});
                }
            }
        }
        return check[n];
    }
};