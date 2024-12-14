class Solution {
public:
    int getAns(vector<vector<int>> &triangle, int i, int j, int &n, vector<vector<int>> &dp){
        if(i == n - 1){
            return triangle[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = triangle[i][j] + min(getAns(triangle,i+1,j,n,dp), getAns(triangle,i+1,j+1,n,dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return getAns(triangle,0,0,n,dp);   
    }
};