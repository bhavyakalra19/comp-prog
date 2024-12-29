class Solution {
public:
    int getAns(vector<int> &prices, int fee, int idx, int buy, vector<vector<int>> &dp){
        if(idx == prices.size()){
            return 0;
        }
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        if(buy == 0){
            int nt = getAns(prices, fee, idx + 1, buy, dp);
            int tk = -prices[idx] - fee + getAns(prices, fee, idx + 1, 1, dp);
            return dp[idx][buy] = max(nt, tk);
        }
        return dp[idx][buy] = max(getAns(prices, fee, idx + 1, buy, dp), prices[idx] + getAns(prices,fee,idx+1,0,dp));
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return getAns(prices, fee, 0, 0, dp);
    }
};