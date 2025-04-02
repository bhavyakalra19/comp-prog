class Solution {
public:
    int getAns(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int a = INT_MAX;
        if(i-1 >= 0) a = min(a, grid[i][j] + getAns(grid, i-1, j, dp));
        if(j-1 >= 0) a = min(a, grid[i][j] + getAns(grid, i, j-1, dp));
        return dp[i][j] = a;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return getAns(grid, n-1, m-1, dp);
    }
};