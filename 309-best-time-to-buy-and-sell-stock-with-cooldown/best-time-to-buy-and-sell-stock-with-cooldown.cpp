class Solution {
public:
    int getAns(vector<int> prices, int idx, vector<vector<int>> &dp, int j){
        if(idx >= prices.size()){
            return 0;
        }
        if(dp[idx][j] != -1){
            return dp[idx][j];
        }
        if(j == 1){
            return dp[idx][j] = max(getAns(prices,idx+1,dp,j), + prices[idx] + getAns(prices, idx+2, dp, 0));
        }
        return dp[idx][j] = max(getAns(prices,idx+1,dp, j), - prices[idx] + getAns(prices,idx+1, dp, 1));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return getAns(prices,0,dp,0);
    }
};