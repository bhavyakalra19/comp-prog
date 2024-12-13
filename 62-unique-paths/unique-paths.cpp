class Solution {
public:
    // int getAns(int m, int n, vector<vector<int>> &dp){
    //     if(m == 0 && n == 0){
    //         return 1;
    //     }
    //     if(m < 0 || n < 0){
    //         return 0;
    //     }
    //     if(dp[m][n] != -1){
    //         return dp[m][n];
    //     }
    //     return dp[m][n] = getAns(m-1,n,dp) + getAns(m,n-1,dp);
    // }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = 1;
        dp[1][1] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(i == 1 && j == 1){
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
        // return getAns(m-1,n-1,dp);
    }
};