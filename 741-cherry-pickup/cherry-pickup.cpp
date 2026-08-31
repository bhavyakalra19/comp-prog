class Solution {
public:
    int n;
    int m;
    bool vis;
    vector<vector<vector<vector<int>>>> dp;
    int getAns(vector<vector<int>> &grid, int i, int j, int x, int y){
        //both will reach same position at same time so need to to worry about grid state
        if(i == n || j == m || x == n || y == m || grid[i][j] == -1 || grid[x][y] == -1){
            return -1e9;
        }
        if(i == n-1 && j == m-1){
            return grid[n-1][m-1];
        }
        if(dp[i][j][x][y] != -1) return dp[i][j][x][y];

        int cherry = 0;
        if(grid[i][j] == 1){
            cherry++;
        }
        if(grid[x][y] == 1 && !(i == x && j == y)){
            cherry++;
        }
        int ans = -1e9;
        ans = max(ans, getAns(grid, i+1, j, x+1, y));
        ans = max(ans, getAns(grid, i, j+1, x+1, y));
        ans = max(ans, getAns(grid, i+1, j, x, y+1));
        ans = max(ans, getAns(grid, i, j+1, x, y+1));
        return dp[i][j][x][y] = cherry + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        // solution is this that there are two bots starting from 0,0 we can go only two paths top to bottom and then bottom to up
        // but how we can find which way has highest instead add two bots from 0,0 and start traversing them to bottom.
        n = grid.size();
        m = grid[0].size();
        dp.resize(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, -1))));
        if(grid[n-1][m-1] == -1) return 0;
        int ans = getAns(grid, 0, 0, 0, 0);
        if(ans < 0) return 0;
        return ans;
    }
};