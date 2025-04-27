class Solution {
public:
    int getAns(vector<int> &prices, int idx, int &fee, int buy, vector<vector<int>> &dp){
        if(idx == prices.size()){
            return 0;
        }
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy == 1){
            return dp[idx][buy] = max(getAns(prices, idx + 1, fee, buy, dp), getAns(prices, idx + 1, fee, 0, dp) - prices[idx] - fee);
        }
        return dp[idx][buy] = max(getAns(prices, idx + 1, fee, buy, dp), prices[idx] + getAns(prices, idx + 1, fee, 1, dp));
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return getAns(prices, 0, fee, 1, dp);
    }
};