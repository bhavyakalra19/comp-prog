class Solution {
public:
    int n;
    int m;
    int getAns(vector<vector<int>> &grid, int i, int j1, int j2, vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j1 == m || j2 < 0 || j2 == m){
            return INT_MIN;
        }
        if(i == n-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }
        int ans = INT_MIN;
        for(int a = -1; a < 2; a++){
            for(int j = -1; j < 2; j++){
                ans = max(ans, getAns(grid,i+1, j1 + a, j2 + j,dp));
            }
        }
        if(j1 == j2){
            return dp[i][j1][j2] = grid[i][j1] + ans;
        }
        return dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m,vector<int>(m,-1)));
        return getAns(grid, 0, 0, m-1, dp);
    }
};
// j == n-1 -> idx1 == idx1 ? grid[idx1][j] : grid[idx1][j] + grid[idx2][j] 

// if idx1 + 1 < m 
// if idx1 - 1 >= 0
// idx1

// if idx2 + 1 < m 
// if idx2 - 1 >= 0
// idx2

// if(idx1 == idx2) else diff