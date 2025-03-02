class Solution {
public:
    int getAns(string &s, int i , int j, int k, vector<vector<vector<int>>> &dp){
        if(i >= j){
            return ((i == j) ? 1 : 0);
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int res = 0;
        int a = abs(s[i] - s[j]);
        int diff = min(a, 26 - a);
        if(diff <= k) res = 2 + getAns(s, i+1, j-1, k - diff, dp);
        return dp[i][j][k] = max(res, max(getAns(s, i, j-1, k, dp),getAns(s, i+1, j, k, dp)));
    }

    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return getAns(s, 0, n-1, k, dp);
    }
};