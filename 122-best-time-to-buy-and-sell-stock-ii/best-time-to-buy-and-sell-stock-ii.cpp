class Solution {
public:
    // int getAns(vector<int> &prices, int idx, int buy, vector<vector<int>> &dp){
    //     if(idx == prices.size()){
    //         return 0;
    //     }
    //     if(dp[idx][buy] != -1){
    //         return dp[idx][buy];
    //     }
    //     if(buy){
    //         return dp[idx][buy] =  max(getAns(prices,idx+1,1,dp), -prices[idx] + getAns(prices,idx+1,0,dp));
    //     }
    //     return dp[idx][buy] = max(getAns(prices,idx+1,0,dp), prices[idx] + getAns(prices,idx+1,1,dp));
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                if(j){
                    dp[i][j] = max(dp[i+1][1], -prices[i] + dp[i+1][0]);
                }else{
                    dp[i][j] = max(dp[i+1][0], prices[i] + dp[i+1][1]);
                }
            }
        }
        return dp[0][1];
        // return getAns(prices,0,1,dp);
    }
};