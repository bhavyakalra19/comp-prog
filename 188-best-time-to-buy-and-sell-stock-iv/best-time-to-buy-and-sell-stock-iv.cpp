class Solution {
public:
    int getAns(vector<int> &prices, int i, int k, vector<vector<int>> &dp){
        if(i == prices.size() || k == 0){
            return 0;
        }
        if(dp[i][k] != -1) return dp[i][k];
        if(k % 2 == 0){
            return dp[i][k] = max(getAns(prices, i + 1, k, dp), getAns(prices, i + 1, k-1, dp) - prices[i]);
        }
        return dp[i][k] = max(getAns(prices, i + 1, k, dp), getAns(prices, i + 1, k-1, dp) + prices[i]);
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k + 1, -1));
        return getAns(prices, 0, 2*k, dp);
    }
};