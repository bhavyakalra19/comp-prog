class Solution {
public:
    int getAns(vector<int> &coins, int idx, int amount, vector<vector<int>> &dp){
        if(amount == 0){
            return 1;
        }
        if(idx == 0){
            return amount % coins[0] == 0;
        }
        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }
        int a = 0;
        int b = getAns(coins, idx - 1, amount, dp);
        if(coins[idx] <= amount){
            a = getAns(coins, idx, amount - coins[idx], dp);
        }
        return dp[idx][amount] = a + b;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return getAns(coins, n-1, amount, dp);
    }
};