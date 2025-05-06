class Solution {
public:
    bool getAns(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i < 0){
            while(j >= 0 && p[j] == '*'){
                j--;
            }
            return j < 0;
        }
        if(j < 0) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(p[j] == '*'){
            return dp[i][j] = getAns(s, p, i, j-1, dp) | getAns(s, p, i-1, j, dp);
        }if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = getAns(s, p, i-1, j-1, dp);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return getAns(s, p, n-1, m-1, dp);
    }
};