class Solution {
public:
    int getAns(vector<int> &prices, int idx, int k, vector<vector<int>> &dp){
        if(idx == prices.size() || k == 0){
            return 0;
        }
        if(dp[idx][k] != -1) return dp[idx][k];
        if(k % 2 == 0){
            return dp[idx][k] = max(getAns(prices, idx + 1, k, dp), getAns(prices, idx + 1, k - 1, dp) - prices[idx]);
        }
        return dp[idx][k] = max(getAns(prices, idx + 1, k, dp), prices[idx] + getAns(prices, idx + 1, k - 1, dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k + 1, -1));
        return getAns(prices, 0, 2 * k, dp);
    }
};

