class Solution {
public:
    // int getAns(vector<int> &coins, int idx, int amount, vector<vector<int>> &dp){
    //     if(amount == 0){
    //         return 0;
    //     }
    //     if(idx == 0){
    //         if(amount % coins[0] == 0){
    //             return amount / coins[0];
    //         }
    //         return INT_MAX;
    //     }
    //     if(dp[idx][amount] != -1){
    //         return dp[idx][amount];
    //     }
    //     int a = INT_MAX;
    //     int b = getAns(coins, idx - 1, amount, dp);
    //     if(coins[idx] <= amount){
    //         a = getAns(coins, idx, amount - coins[idx], dp);
    //     }
    //     if(a != INT_MAX){
    //         a += 1;
    //     }
    //     return dp[idx][amount] = min(a,b);
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,INT_MAX));
        for(int i = 0; i < n; i++){
            dp[i][0] = 0;
        }

        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= amount; j++){
                int a = INT_MAX;
                int b = dp[i-1][j];
                if(coins[i] <= j){
                    a = dp[i][j - coins[i]];
                }
                if(a != INT_MAX){
                    a += 1;
                }
                dp[i][j] = min(a,b);
            }
        }
        return dp[n-1][amount] == INT_MAX ? -1 : dp[n-1][amount];
        // int a = getAns(coins, n-1, amount, dp);
        // return a == INT_MAX ? -1 : a;
    }
};