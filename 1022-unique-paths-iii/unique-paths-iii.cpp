class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    void getAns(vector<vector<int>> &grid, int i, int j, int n, int m, int &ans, int check){
        if(grid[i][j] == 2){
            if(check == -1) ans++;
            return;
        }
        grid[i][j] = 3;
        for(int a = 0; a < 4; a++){
            int nx = i + dx[a];
            int ny = j + dy[a];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && (grid[nx][ny] == 0 || grid[nx][ny] == 2)){
                getAns(grid,nx,ny,n,m,ans,check-1);
            }
        }
        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int st1;
        int st2;
        int check = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    st1 = i;
                    st2 = j;                    
                }
                if(grid[i][j] == 0){
                    check++;
                }
            }
        }
        getAns(grid, st1, st2, n, m, ans, check);
        return ans;
    }
};