class Solution {
public:
    int n;
    
    int getAns(vector<vector<int>> &grid, int r1, int c1, int r2, int c2, vector<vector<vector<vector<int>>>> &dp){
        if((r1 == n-1 && c1 == n-1) || (r2 == n-1 && c2 == n-1)){
            return grid[n-1][n-1];
        }
        if(r1 == n || c1 == n || r2 == n || c2 == n) return INT_MIN;
        if(grid[r1][c1] == -1 || grid[r2][c2] == -1) return dp[r1][c1][r2][c2] = INT_MIN;
        if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];
        int sum = (((r1 == r2) && (c1 == c2)) ? grid[r1][c1] : (grid[r1][c1] + grid[r2][c2]));
        int cherry1 = max(getAns(grid, r1 + 1, c1, r2 + 1, c2, dp), getAns(grid, r1 + 1, c1, r2, c2 + 1, dp));
        int cherry2 = max(getAns(grid, r1, c1 + 1, r2 + 1, c2, dp), getAns(grid, r1, c1 + 1, r2, c2 + 1, dp));
        int cherry = max(cherry1, cherry2);
        if(cherry == INT_MIN) return dp[r1][c1][r2][c2] = INT_MIN;
        return dp[r1][c1][r2][c2] = cherry + sum;
    }

    int cherryPickup(vector<vector<int>>& grid){
        n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n,-1))));
        int a = getAns(grid, 0, 0, 0, 0, dp);
        return a == INT_MIN ? 0 : a;
    }
};