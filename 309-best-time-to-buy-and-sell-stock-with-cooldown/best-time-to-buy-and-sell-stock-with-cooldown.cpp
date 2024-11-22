class Solution {
public:
    int getAns(vector<int> prices, int idx, vector<vector<int>> &dp, int j, int prev){
        if(idx >= prices.size()){
            return 0;
        }
        if(dp[idx][j] != -1){
            return dp[idx][j];
        }
        if(prev < prices[idx] && j == 1){
            return dp[idx][j] = max(getAns(prices,idx+1,dp,j,0), + prices[idx] + getAns(prices, idx+2, dp, 0,0));
        }
        return dp[idx][j] = max(getAns(prices,idx+1,dp, j,prev), - prices[idx] + getAns(prices,idx+1, dp, 1, prices[idx]));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return getAns(prices,0,dp,0,0);
    }
};