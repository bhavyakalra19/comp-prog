class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        int n = coins.size();
        for(int i = 1; i <= amount; i++){
            for(auto c : coins){
                if(i - c < 0){
                    continue;
                }
                dp[i] = min(dp[i], dp[i-c]);
            }
            if(dp[i] != INT_MAX){
                dp[i] += 1;
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};