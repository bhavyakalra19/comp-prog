class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m,vector<int>(m,0)));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(i == j){
                    dp[n-1][i][j] = grid[n-1][i];
                }else{
                    dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
                }
            }
        }
        for(int i = n-2; i >= 0; i--){
            for(int j1 = 0; j1 < m; j1++){
                for(int j2 = 0; j2 < m; j2++){
                    int ans = INT_MIN;
                    int val = grid[i][j1];
                    if(j1 != j2){
                        val += grid[i][j2];
                    }
                    for(int a = -1; a <= 1; a++){
                        for(int b = -1; b <= 1; b++){
                            if((j1 + a < m) && (j1 + a >= 0) && (j2 + b >= 0) && (j2 + b < m)){
                                ans = max(ans, dp[i + 1][j1 + a][j2 + b]);
                            }
                        }
                    }
                    dp[i][j1][j2] = val + ans;
                }
            }
        }
        return dp[0][0][m-1];
    }
};
