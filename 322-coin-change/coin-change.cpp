class Solution {
public:
    int getAns(vector<int> &coins, int idx, int amount, vector<vector<int>> &dp){
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
        int a = INT_MAX;
        int b = getAns(coins, idx - 1, amount, dp);
        if(coins[idx] <= amount){
            a = getAns(coins, idx, amount - coins[idx], dp);
        }
        if(a != INT_MAX){
            a += 1;
        }
        return dp[idx][amount] = min(a,b);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int a = getAns(coins, n-1, amount, dp);
        return a == INT_MAX ? -1 : a;
    }
};