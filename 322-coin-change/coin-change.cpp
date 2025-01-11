class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));
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
                    a++;
                }
                dp[i][j] = min(a,b);
            }
        }
        // int a = getAns(coins,n-1,amount,dp);
        // return a == INT_MAX ? -1 : a;
        return dp[n-1][amount] != INT_MAX ? dp[n-1][amount] : -1;
    }
};

// f(coins, idx , amount)
// f(coins, idx - 1, amount)
// f(coins, idx,amount - coins[i])


// if(amount == 0){
//     return 0;
// }
// if(idx == 0){
//     if amount % coins[idx] == 0 return amount / coins[idx];
//     return INT_MAX;
// }
