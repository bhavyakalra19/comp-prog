class Solution {
public:
    int mod = 1e9 + 7;
    int n;
    int m;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    int getAns(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int a = 0; a < 4; a++){
            int nx = i + dx[a];
            int ny = j + dy[a];
            if(nx < 0 || nx == n || ny < 0 || ny == m || grid[nx][ny] <= grid[i][j]) continue;
            ans = (ans + getAns(grid, nx, ny, dp)) % mod;
        }
        return dp[i][j] = 1 + ans;
    }

    int countPaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dp[i][j] == -1){
                    dp[i][j] = getAns(grid, i, j, dp);
                }
                ans = (ans + dp[i][j]) % mod;
            }
        }
        return ans;
    }
};

