class Solution {
public:

    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<long long>> dp(4, vector<long long>(4, 0));
        for(int i = n/2 - 1; i >= 0; i--){
            vector<vector<long long>> curr(4, vector<long long>(4, LONG_MAX));
            for(int p1 = 0; p1 <= 3; p1++){
                for(int p2 = 0; p2 <= 3; p2++){
                    for(int c1 = 0; c1 < 3; c1++){
                        if(c1 != p1){
                            for(int c2 = 0; c2 < 3; c2++){
                                if(c1 == c2 || c2 == p2){
                                    continue;
                                }
                                curr[p1][p2] = min(curr[p1][p2],  (long long) cost[i][c1] + (long long) cost[n - i - 1][c2] + dp[c1][c2]);
                            }
                        }
                    }
                }
            }
            dp = curr;
        }
        return dp[3][3];
    }
};

