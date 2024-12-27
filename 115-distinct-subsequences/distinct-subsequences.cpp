class Solution {
public:
    int getAns(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        if(j < 0){
            return 1;
        }
        if(i < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j] = getAns(s1,s2,i-1,j-1,dp) + getAns(s1,s2,i-1,j,dp);
        }
        return dp[i][j] = getAns(s1,s2,i-1,j,dp);
    }

    int numDistinct(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return getAns(s1,s2,n-1,m-1,dp);
    }
};