class Solution {
public:
    // int getAns(int m, int n, vector<vector<int>> &dp){
    //     if(m == 0 && n == 0){
    //         return 1;
    //     }
    //     if(dp[m][n] != -1){
    //         return dp[m][n];
    //     }
    //     int a = 0;
    //     if(m - 1 >= 0){
    //         a = getAns(m-1,n,dp);
    //     }
    //     int b = 0;
    //     if(n - 1 >= 0){
    //         b = getAns(m,n-1,dp);
    //     }
    //     return dp[m][n] = a + b;
    // }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int>(n,0));
        vector<int> prev(n,0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    prev[j] = 1;
                }else{
                    int a = 0;
                    int b = 0;
                    if(i - 1 >= 0){
                        a = prev[j];
                    }
                    if(j - 1 >= 0){
                        b = prev[j-1];
                    }
                    prev[j] = a + b;
                }
            }
        }
        return prev[n-1];
        // return getAns(m-1,n-1,dp);

    }
};