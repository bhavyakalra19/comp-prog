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
        // vector<vector<int>> dp(n+1, vector<int>(2,0));
        vector<int> prev(2,0);
        vector<int> curr(2,0);
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                if(j == 0){
                    curr[j] = max(prev[j], -prices[i] - fee + prev[1]);
                }else{
                    curr[j] = max(prev[j], prices[i] + prev[0]);
                }
            }
            prev = curr;
        }
        return prev[0];
        // return getAns(prices, fee, 0, 0, dp);
    }
};