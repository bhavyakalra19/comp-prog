class Solution {
public:
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, 1, -1};
    int n;
    int m;
    int dfs(vector<vector<int>> &grid, int i, int j, int ch, int a){
        int ans = 0;
        if(ch){
            int b = (a + 1) % 4;
            int nx = i + dx[b];
            int ny = j + dy[b];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if((grid[i][j] == 2 && grid[nx][ny] == 0) || (grid[i][j] == 0 && grid[nx][ny] == 2)){
                    ans = max(ans, dfs(grid, nx, ny, 0, b));
                }
            }
        }
        int nx = i + dx[a];
        int ny = j + dy[a];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
            if((grid[i][j] == 2 && grid[nx][ny] == 0) || (grid[i][j] == 0 && grid[nx][ny] == 2)){
                ans = max(ans, dfs(grid, nx, ny, ch, a));
            }
        }
        return ans + 1;
    }


    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    ans = max(ans, 1);
                    for(int a = 0; a < 4; a++){
                        int nx = i + dx[a];
                        int ny = j + dy[a];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                            if(grid[nx][ny] == 2){
                                ans = max(ans, 1 + dfs(grid, nx, ny, 1, a));
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};