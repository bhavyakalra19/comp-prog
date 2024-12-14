class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }else{
                    int a = i > 0 ? dp[i-1][j] : INT_MAX;
                    int b = j > 0 ? dp[i][j-1] : INT_MAX;
                    dp[i][j] = grid[i][j] + min(a,b);
                }
            }
        }
        return dp[m-1][n-1];
    }
};