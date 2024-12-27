class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2*k + 1,0);
        for(int i = n-1; i >= 0; i--){
            vector<int> curr(2*k + 1,0);
            for(int j = 0; j < 2*k; j++){
                if(j % 2 == 0){
                    curr[j] = max(dp[j], -prices[i] + dp[j+1]);
                }else{
                    curr[j] = max(dp[j], prices[i] + dp[j+1]);
                }
            }
            dp = curr;
        }
        return dp[0];
    }
};