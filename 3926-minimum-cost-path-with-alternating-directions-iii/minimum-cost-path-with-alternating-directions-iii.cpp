class Solution {
public:
    
    long long minCost(int n, int m, vector<vector<int>>& penalty) {
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(2, LONG_MAX)));
        priority_queue<pair<long long, pair<int, pair<int,int>>>, vector<pair<long long, pair<int, pair<int,int>>>>, greater<pair<long long, pair<int, pair<int,int>>>>> pq;
        pq.push({1, {1, {0, 0}}});
        dp[0][0][1] = 1;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long cw = it.first;
            int cp = it.second.first;
            int cx = it.second.second.first;
            int cy = it.second.second.second;
            
            if (cw > dp[cx][cy][cp]) continue;

            int np = cp ^ 1;
            long long ncw = penalty[cx][cy] + cw;

            if(dp[cx][cy][np] > ncw){
                dp[cx][cy][np] = ncw;
                pq.push({ncw, {np, {cx, cy}}});
            }

            for(int a = 0; a < 4; a++){
                int nx = cx + dx[a];
                int ny = cy + dy[a];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    long long nw = (nx + 1) * (ny + 1) + cw;
                    if(cp == 1 && a < 2){
                        // even move -> right or down then pay penalty;
                        nw += penalty[cx][cy];
                    }else if(cp == 0 && a > 1){
                        // odd move -> left or up then pay penalty;
                        nw += penalty[cx][cy];
                    }

                    if(dp[nx][ny][np] > nw){
                        dp[nx][ny][np] = nw;
                        pq.push({nw, {np, {nx, ny}}});
                    }
                }
            }
        }
        return min(dp[n-1][m-1][0], dp[n-1][m-1][1]);
    }
};

// dijkstra with odd/even parity
// i + 1 * j + 1

// i, j, parity