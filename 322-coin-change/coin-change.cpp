class Solution {
public:
    int getAns(vector<int> &coins, int amount, int idx, int n, vector<int> &dp){
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, getAns(coins,amount - coins[i], i, n, dp)); 
        }
        return dp[amount] = ((ans == INT_MAX) ? ans : ans + 1);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,-1);
        int ans = getAns(coins, amount, 0, n, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};