class Solution {
public:
    int getAns(int m, int n, int i, int j){
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        if(i == m  || j == n){
            return 0;
        }

        return getAns(m,n,i+1,j) + getAns(m,n,i,j+1);
    }

    int uniquePaths(int m, int n) {
        // return getAns(m, n, 0, 0);
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};