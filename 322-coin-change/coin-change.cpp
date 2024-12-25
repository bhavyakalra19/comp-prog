class Solution {
public:
    int getAns(vector<int> &coins, int amount, int idx, vector<vector<int>> &dp){
        if(amount == 0){
            return 0;
        }
        if(idx == 0){
            if(amount % coins[0] == 0){
                return amount / coins[0];
            }
            return INT_MAX;
        }
        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }
        int nt = getAns(coins, amount, idx - 1, dp);
        int tk = INT_MAX;
        if(coins[idx] <= amount){
            tk = min(getAns(coins, amount - coins[idx], idx, dp), getAns(coins, amount - coins[idx], idx - 1, dp));
        }
        if(tk != INT_MAX){
            tk++;
        }
        return dp[idx][amount] = min(nt,tk);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,INT_MAX));
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }
        }
        dp[0][0] = 0;
        for(int i = 1; i < n; i++){
            dp[i][0] = 0;
            for(int j = 1; j <= amount; j++){
                int nt = dp[i-1][j];
                int tk = INT_MAX;
                if(coins[i] <= j){
                    tk = min(dp[i-1][j-coins[i]], dp[i][j-coins[i]]);
                }
                if(tk != INT_MAX){
                    tk++;
                }
                dp[i][j] = min(nt, tk);
            }
        }
        return dp[n-1][amount] == INT_MAX ? -1 : dp[n-1][amount];
        // int a = getAns(coins, amount, n-1,dp);
        // return a == INT_MAX ? -1 : a;
    }
};