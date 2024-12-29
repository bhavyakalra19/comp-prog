class Solution {
public:
    // int getAns(vector<int> &prices, int fee, int idx, int buy, vector<vector<int>> &dp){
    //     if(idx == prices.size()){
    //         return 0;
    //     }
    //     if(dp[idx][buy] != -1){
    //         return dp[idx][buy];
    //     }
    //     if(buy == 0){
    //         int nt = getAns(prices, fee, idx + 1, buy, dp);
    //         int tk = -prices[idx] - fee + getAns(prices, fee, idx + 1, 1, dp);
    //         return dp[idx][buy] = max(nt, tk);
    //     }
    //     return dp[idx][buy] = max(getAns(prices, fee, idx + 1, buy, dp), prices[idx] + getAns(prices,fee,idx+1,0,dp));
    // }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                if(j == 0){
                    dp[i][j] = max(dp[i+1][j], -prices[i] - fee + dp[i+1][1]);
                }else{
                    dp[i][j] = max(dp[i+1][j], prices[i] + dp[i+1][0]);
                }
            }
        }
        return dp[0][0];
        // return getAns(prices, fee, 0, 0, dp);
    }
};