class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // do union and find from 1 and check all nodes which we can go to and find min node in all the ways
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto &a : roads){
            graph[a[0]].push_back({a[1], a[2]});
            graph[a[1]].push_back({a[0], a[2]});
        }
        int mn = INT_MAX;
        vector<bool> vis(n+1, false);
        queue<int> q;
        q.push(1);
        vis[1] = true;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(auto &a : graph[it]){
                int nx = a.first;
                int nw = a.second;
                mn = min(mn, nw);
                if(!vis[nx]){
                    q.push(nx);
                }
                vis[nx] = true;
            }
        }
        return mn;
    }
};