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

        int nt = getAns(coins, idx-1, amount, dp);
        int tk = INT_MAX;
        if(coins[idx] <= amount) tk = getAns(coins,idx,amount - coins[idx],dp);
        if(tk != INT_MAX) tk += 1;
        return dp[idx][amount] = min(nt, tk);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int a = getAns(coins, n-1, amount, dp);
        if(a == INT_MAX){
            return -1;
        }
        return a;
    }
};