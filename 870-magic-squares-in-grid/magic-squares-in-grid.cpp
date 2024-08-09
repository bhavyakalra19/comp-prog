class Solution {
public:
    int checkMat(vector<vector<int>> grid, int r, int c){
        int row1 = grid[r][c] + grid[r+1][c] + grid[r+2][c];
        int row2 = grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1];
        int row3 = grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2];
        if(row1 != row2 || row2 != row3){
            return 0;
        }

        int col1  = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        int col2  = grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2];
        int col3  = grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2];
        if(col1 != col2 || col2 != col3){
            return 0;
        }
        int d1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        int d2 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];
        if(d1 != d2){
            return 0;
        }

        unordered_map<int,int> mp;
        for(int i = r; i < r + 3; i++){
            for(int j = c; j < c + 3; j++){
                if(grid[i][j] == 0 || grid[i][j] > 9 || mp[grid[i][j]] == 1){
                    return 0;
                }
                mp[grid[i][j]] += 1;
            }
        }
        return 1;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m - 2; i++){
            for(int j = 0; j < n - 2; j++){
                ans += checkMat(grid,i,j);
            }
        }
        return ans;
    }
};