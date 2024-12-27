class Solution {
public:
    int getAns(vector<int> &prices, int idx, int buy, vector<vector<int>> &dp){
        if(idx >= prices.size()){
            return 0;
        }
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        if(buy){
            return dp[idx][buy] = max(getAns(prices,idx+1,buy,dp), -prices[idx] + getAns(prices,idx+1,0,dp));
        }
        return dp[idx][buy] = max(getAns(prices,idx+1,buy,dp), prices[idx] + getAns(prices,idx+2,1,dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return getAns(prices,0,1,dp);
    }
};