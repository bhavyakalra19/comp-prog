class Solution {
public:
    // int getAns(vector<vector<int>> &grid, int idx, int j1, int j2, int n, int m, vector<vector<vector<int>>> &dp){
    //     if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){
    //         return INT_MIN;
    //     }
    //     if(idx == n - 1){
    //         if(j1 == j2){
    //             return grid[idx][j1];
    //         }
    //         return grid[idx][j1] + grid[idx][j2];
    //     }
    //     if(dp[idx][j1][j2] != -1){
    //         return dp[idx][j1][j2];
    //     }
    //     int mx = INT_MIN;
    //     for(int i1 = -1; i1 <= 1; i1++){
    //         for(int i2 = -1; i2 <= 1; i2++){
    //             mx = max(mx, getAns(grid, idx + 1, j1 + i1, j2 + i2, n, m, dp));
    //         }
    //     }
    //     int val = ((j1 == j2) ? grid[idx][j1] : grid[idx][j1] + grid[idx][j2]);
    //     return dp[idx][j1][j2] = (val + mx);
    // }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        // return getAns(grid,0,0,m-1,n,m,dp);
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                if(j1 == j2){
                    dp[n-1][j1][j2] = grid[n-1][j1];
                }else{
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
        }

        for(int i = n-2; i >= 0; i--){
            for(int j1 = 0; j1 < m; j1++){
                for(int j2 = 0; j2 < m; j2++){
                    int val = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                    int mx = -1e8;
                    for(int i1 = -1; i1 <= 1; i1++){
                        for(int i2 = -1; i2 <= 1; i2++){
                            if((j1 + i1 >= 0) && (j1 + i1 < m) && (j2 + i2 >= 0) && (j2 + i2 < m)){
                                mx = max(mx, dp[i+1][j1 + i1][i2 + j2]);
                            }
                        }
                    }
                    dp[i][j1][j2] = val + mx;
                }
            }
        }
        return dp[0][0][m-1];
    }
};