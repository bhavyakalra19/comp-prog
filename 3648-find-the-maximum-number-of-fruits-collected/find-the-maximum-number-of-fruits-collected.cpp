class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            ans += fruits[i][i];
            fruits[i][i] = -1;
        }
        dp[n-1][n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                dp[i][j] = dp[i+1][j];
                if(fruits[i][j-1] != -1) dp[i][j] = max(dp[i][j], dp[i+1][j-1]);
                if(j + 1 < n) dp[i][j] = max(dp[i][j], dp[i+1][j+1]);
                dp[i][j] += fruits[i][j];
            }
        }
        for(int j = n-2; j >= 0; j--){
            for(int i = j+1; i < n; i++){
                dp[i][j] = dp[i][j+1];
                if(fruits[i-1][j] != -1){
                    dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
                }
                if(i + 1 < n){
                    dp[i][j] = max(dp[i][j], dp[i+1][j+1]);
                }
                dp[i][j] += fruits[i][j];
            }
        }
        return ans + dp[0][n-1] + dp[n-1][0];
    }
};
