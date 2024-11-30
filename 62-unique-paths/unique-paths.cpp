class Solution {
public:
    int getAns(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        if(i == m  || j == n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = getAns(m,n,i+1,j,dp) + getAns(m,n,i,j+1,dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return getAns(m, n, 0, 0, dp);
        // dp[0][0] = 1;
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         if(i == 0 || j == 0) dp[i][j] = 1;
        //         else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        //     }
        // }
        // return dp[m-1][n-1];
    }
};