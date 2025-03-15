class Solution {
public:
    int n;
    int m;
    int getAns(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
        if(i == n || j == m) return 1e9;
        if(i == n-1 && j == m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(getAns(grid, i + 1, j, dp), getAns(grid, i, j+1, dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return getAns(grid, 0, 0, dp);
    }
};