class Solution {
public:
    int n;
    int m;
    int dx[4] = {-1,-1,1,1};
    int dy[4] = {-1,1,1,-1};
    int getAns(vector<vector<int>> &grid, int i, int j, int ch, int a,vector<vector<vector<vector<int>>>> &dp){
        int ans = 1;
        if(dp[i][j][ch][a] != -1) return dp[i][j][ch][a];
        if(ch == 1){
            int nx = i + dx[(a + 1)%4];
            int ny = j + dy[(a + 1)%4];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(grid[i][j] == 0 && grid[nx][ny] == 2){
                    ans = max(ans, 1 + getAns(grid, nx, ny, 0, (a+1)%4, dp));
                }else if(grid[i][j] == 2 && grid[nx][ny] == 0){
                    ans = max(ans, 1 + getAns(grid, nx, ny, 0, (a+1)%4, dp));
                }
            }
        }
        int nx = i + dx[a];
        int ny = j + dy[a];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
            if(grid[i][j] == 0 && grid[nx][ny] == 2){
                ans = max(ans, 1 + getAns(grid, nx, ny, ch, a, dp));
            }else if(grid[i][j] == 2 && grid[nx][ny] == 0){
                ans = max(ans, 1 + getAns(grid, nx, ny, ch, a, dp));
            }
        }
        return dp[i][j][ch][a] = ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(2,vector<int>(4,-1))));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    ans = max(ans, 1);
                    for(int a = 0; a < 4; a++){
                        int nx = i + dx[a];
                        int ny = j + dy[a];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 2){
                             ans = max(ans, 1 + getAns(grid, nx, ny, 1, a, dp));
                        }
                    }
                }
            }
        }
        return ans;
    }
};