class Solution {
public:
    // int getAns(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
    //     if(i == 0 & j == 0){
    //         return 1;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int a = 0;
    //     int b = 0;
    //     if(i - 1 >= 0 && !grid[i-1][j]){
    //         a = getAns(grid,i-1,j,dp);
    //     }
    //     if(j - 1 >= 0 && !grid[i][j-1]){
    //         b = getAns(grid,i,j-1,dp);
    //     }
    //     return dp[i][j] = a + b;
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }else{
                    int a = 0;
                    int b = 0;
                    if(i - 1 >= 0 && !obstacleGrid[i-1][j]){
                        a = dp[i-1][j];
                    }
                    if(j - 1 >= 0 && !obstacleGrid[i][j-1]){
                        b = dp[i][j-1];
                    }
                    dp[i][j] = a + b;
                }
            }
        }
        return dp[n-1][m-1];
        // return getAns(obstacleGrid, n-1, m-1, dp);
    }
};