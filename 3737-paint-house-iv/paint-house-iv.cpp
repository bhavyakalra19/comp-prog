class Solution {
public:
    long long getAns(vector<vector<int>> &costs, int idx, int p1, int p2, int &n, vector<vector<vector<long long>>> &dp){
        if(idx == n/2){
            return 0;
        }
        if(dp[idx][p1][p2] != -1){
            return dp[idx][p1][p2];
        }
        long long ans = LONG_MAX;
        for(int c1 = 0; c1 < 3; c1++){
            for(int c2 = 0; c2 < 3; c2++){
                if(c1 == c2){
                    continue;
                }
                if(c1 == p1 || c2 == p2){
                    continue;
                }
                ans = min(ans,  (long long) costs[idx][c1] + (long long) costs[n - idx - 1][c2] + getAns(costs, idx + 1, c1, c2, n, dp));
            }
        }
        return dp[idx][p1][p2] = ans;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<long long>>> dp(n/2 + 1, vector<vector<long long>>(4, vector<long long>(4, LONG_MAX)));
        for(int i = 0; i <= 3; i++){
            for(int j = 0; j <= 3; j++){
                dp[n/2][i][j] = 0;
            }
        }
        for(int i = n/2 - 1; i >= 0; i--){
            long long ans = LONG_MAX;
            for(int p1 = 0; p1 <= 3; p1++){
                for(int p2 = 0; p2 <= 3; p2++){
                    for(int c1 = 0; c1 < 3; c1++){
                        for(int c2 = 0; c2 < 3; c2++){
                            if(c1 == c2){
                                continue;
                            }
                            if(c1 == p1 || c2 == p2){
                                continue;
                            }
                            dp[i][p1][p2] = min(dp[i][p1][p2],  (long long) cost[i][c1] + (long long) cost[n - i - 1][c2] + dp[i+1][c1][c2]);
                        }
                    }
                }
            }
        }
        return dp[0][3][3];
        // return getAns(cost, 0, 3, 3, n, dp);
    }
};

