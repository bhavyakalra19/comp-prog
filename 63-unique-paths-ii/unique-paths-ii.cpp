class Solution {
public:
    // int getAns(vector<vector<int>> &check, int i, int j, vector<vector<int>> &dp){
    //     if(i < 0 || j < 0 || check[i][j] == 1){
    //         return 0;
    //     }
    //     if(i == 0 && j == 0){
    //         return 1;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     return dp[i][j] = getAns(check,i-1,j,dp) + getAns(check,i,j-1,dp);
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // We only need prev row data and current row data so why use extra space
        // vector<vector<int>> dp(m,vector<int>(n,-1));

        vector<int> prev(n,0);
        for(int i = 0; i < m; i++){
            vector<int> curr(n,0);
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    curr[j] = 0;
                }else if(i == 0 && j == 0){
                    curr[j] = 1;
                }else{
                    int a = (i > 0) ? prev[j] : 0;
                    int b = (j > 0) ? curr[j-1] : 0;
                    curr[j] = a + b;
                } 
            }
            prev = curr;
        }
        return prev[n-1];
    }
};