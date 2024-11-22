class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n + 2, vector<int>(2));
        
        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy) {
                    dp[i][buy] = max(-p[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                }
                else dp[i][buy] = max(p[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
            }
        }
        return dp[0][1];
    }
};