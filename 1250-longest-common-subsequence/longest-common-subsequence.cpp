class Solution {
public:
    int getAns(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        if(i < 0 || j < 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + getAns(s1, s2, i - 1, j - 1, dp);
        }
        return dp[i][j] = max(getAns(s1,s2,i-1,j,dp), getAns(s1,s2,i,j-1,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),-1));
        return getAns(text1, text2, text1.size() - 1, text2.size() - 1, dp);
    }
};