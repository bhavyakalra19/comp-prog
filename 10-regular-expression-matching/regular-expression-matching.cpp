class Solution {
public:
    int n;
    int m;
    bool getAns(string s, string p, int i, int j, vector<vector<int>> &dp){
        if(i < 0 && j < m){
            return true;
        }
        if(i < 0 && p[j] == '*'){
            return getAns(s,p,i,j-2,dp);
        }
        if(i < 0 || j < m){
            return false;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(p[j] == '*'){
            bool a = getAns(s,p,i,j-2,dp);
            if(s[i] == p[j-1] || p[j-1] == '.'){
                a = getAns(s,p,i-1,j,dp) || a;
            }
            return dp[i][j] = a;
        }else if(s[i] == p[j] || p[j] == '.'){
            return dp[i][j] = getAns(s,p,i-1,j-1,dp);
        }
        return false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return getAns(s,p,n-1,m-1,dp);
    }
};