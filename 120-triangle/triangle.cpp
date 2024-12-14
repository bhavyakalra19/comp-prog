class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Why we need dp array if we can use current triangle
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return getAns(triangle,0,0,n,dp);
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        } 
        return triangle[0][0];
    }
};