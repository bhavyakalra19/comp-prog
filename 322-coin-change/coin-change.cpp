class Solution {
public:
    int getAns(vector<int> &coins, int amount, int idx, vector<vector<int>> &dp){
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
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int a = getAns(coins, amount, n-1,dp);
        return a == INT_MAX ? -1 : a;
    }
};