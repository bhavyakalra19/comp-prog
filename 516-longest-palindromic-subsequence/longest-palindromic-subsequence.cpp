class Solution {
public:
    int getAns(string s1, int i, string s2, int j, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + getAns(s1, i-1, s2, j-1, dp);
        }
        return dp[i][j] = max(getAns(s1, i - 1, s2, j, dp), getAns(s1, i, s2, j - 1, dp));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        reverse(s2.begin(), s2.end());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(s[i] == s2[j]){
                    dp[i+1][j+1] = 1 + dp[i][j];
                }else{
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        return dp[n][n];
    }
};