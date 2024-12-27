class Solution {
public:
    // int getAns(vector<int> &prices, int idx, int cap, vector<vector<int>> &dp){
    //     if(idx == prices.size() || cap == 4){
    //         return 0;
    //     }
    //     if(dp[idx][cap] != -1){
    //         return dp[idx][cap];
    //     }
    //     if(cap == 0 || cap == 2){
    //         return dp[idx][cap] = max(getAns(prices,idx+1,cap,dp), -prices[idx] + getAns(prices,idx+1,cap+1,dp));
    //     }
    //     return dp[idx][cap] = max(getAns(prices,idx+1,cap,dp), prices[idx] + getAns(prices,idx+1,cap+1,dp));
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(5,0));
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 4; j++){
                if(j == 0 || j == 2){
                    dp[i][j] = max(dp[i+1][j], -prices[i] + dp[i+1][j+1]);
                }else{
                    dp[i][j] = max(dp[i+1][j], prices[i] + dp[i+1][j+1]);
                }
            }
        }
        return dp[0][0];
        // return getAns(prices,0,0,dp);
    }
};
