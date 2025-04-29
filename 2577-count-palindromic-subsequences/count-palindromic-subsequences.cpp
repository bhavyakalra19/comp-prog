class Solution {
public:
    int mod = 1e9 + 7;
    void resetMemeCache(vector<vector<int>> &dp, int &n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                dp[i][j] = -1;
            }
        }
    }   

    int getAns(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(j == 5) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(p[j] == '*' || s[i] == p[j]){
            ans = getAns(s, p, i+1, j+1, dp);
        }
        ans = (ans + getAns(s, p, i+1, j, dp)) % mod;
        return dp[i][j] = ans;
    }

    int countPalindromes(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(5,-1));
        for(char i = '0'; i <= '9'; i++){
            for(char j = '0'; j <= '9'; j++){
                string pat = string() = {i, j, '*', j, i};
                ans = (ans + getAns(s, pat, 0, 0, dp)) % mod;
                resetMemeCache(dp, n);
            }
        }
        return ans;
    }
};