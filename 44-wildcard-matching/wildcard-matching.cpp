class Solution {
public:
    bool getAns(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        if(i < 0 && j < 0){
            return true;
        }
        if(j < 0){
            return false;
        }
        if(i < 0){
            while(j >= 0 && s2[j] == '*'){
                j--;
            }
            if(j < 0) return true;
            return false;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j] || s2[j] == '?'){
            return dp[i][j] = getAns(s1,s2,i-1,j-1,dp);
        }else if(s2[j] == '*'){
            return dp[i][j] = getAns(s1,s2,i-1,j,dp) | getAns(s1,s2,i-1,j-1,dp) | getAns(s1,s2,i,j-1,dp);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return getAns(s,p,n-1,m-1,dp);
    }
};