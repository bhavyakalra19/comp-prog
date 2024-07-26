#define INF 10001

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INF));
        int ans = 0;
        int mn = INT_MAX;
        for(int i = 0; i < edges.size(); i++){
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
         for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            int check = 0;
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                if(min(dist[i][j],dist[j][i]) <= distanceThreshold){
                    check += 1;
                }
            }
            if(check <= mn){
                mn = check;
                ans = i;
            }
        }
        return ans;
    }
};