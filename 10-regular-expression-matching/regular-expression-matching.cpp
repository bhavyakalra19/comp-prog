class Solution {
public:
    bool getAns(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i < 0){
            while(j >= 0 && p[j] == '*'){
                j -= 2;
            }
            return j < 0;
        }
        if(j < 0) return false;
        if(dp[i][j] != -1) return dp[i][j];
        bool a = false;
        if(s[i] == p[j] || p[j] == '.'){
            a = getAns(s, p, i-1, j-1, dp);
        }else if(p[j] == '*'){
            a = a | getAns(s, p, i, j-2, dp);
            if(p[j-1] == s[i] || p[j-1] == '.'){
                a = a | getAns(s, p, i-1, j, dp);
            }
        }
        return dp[i][j] = a;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return getAns(s, p, n-1, m-1, dp);
    }
};