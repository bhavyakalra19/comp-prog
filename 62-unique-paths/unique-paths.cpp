class Solution {
public:
    int getAns(int m, int n, vector<vector<int>> &dp){
        if(m == 0 && n == 0){
            return 1;
        }
        if(m < 0 || n < 0){
            return 0;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        return dp[m][n] = getAns(m-1,n,dp) + getAns(m,n-1,dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return getAns(m-1,n-1,dp);
    }
};