class Solution {
public:
    void dfs(vector<vector<int>> &check,int i, int j, int n){
        if(i == n || i < 0 || j == n || j < 0 || check[i][j] == -1){
            return;
        }
        check[i][j] = -1;
        dfs(check,i+1,j,n);
        dfs(check,i,j+1,n);
        dfs(check,i-1,j,n);
        dfs(check,i,j-1,n);
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<vector<int>> check(n*3,vector<int>(3*n,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/'){
                    check[3*i][3*j + 2] = -1;
                    check[3*i + 1][3*j + 1] = -1;
                    check[3*i + 2][3*j] = -1;
                }else if(grid[i][j] == '\\'){
                    check[3*i][3*j] = -1;
                    check[3*i + 1][3*j + 1] = -1;
                    check[3*i + 2][3*j + 2] = -1;
                }
            }
        }
        for(int i = 0; i < 3*n; i++){
            for(int j = 0; j < 3*n; j++){
                if(check[i][j] == 0){
                    ans += 1;
                    dfs(check,i,j,3*n);
                }
            }
        }
        return ans;
    }
};