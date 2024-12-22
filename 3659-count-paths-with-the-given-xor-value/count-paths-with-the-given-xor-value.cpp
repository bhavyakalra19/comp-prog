class Solution {
public:
    const int mod = 1000000007;
    int getAns(vector<vector<int>> &grid, int n, int m, int k, vector<vector<vector<int>>> &dp, int curr){
        if(n < 0 || m < 0){
            return 0;
        }
        curr ^= grid[n][m];
        if(n == 0 && m == 0){
            return curr == k;
        }
        if(dp[n][m][curr] != -1){
            return dp[n][m][curr];
        }
        int top = getAns(grid,n-1,m,k,dp,curr) % mod;
        int left = getAns(grid,n,m-1,k,dp,curr) % mod;
        return dp[n][m][curr] = (top + left) % mod;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(16,-1)));
        return getAns(grid,n-1,m-1,k,dp,0);
    }
};