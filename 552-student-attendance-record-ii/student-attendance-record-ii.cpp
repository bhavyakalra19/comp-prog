class Solution {
public:
    int mod = 1e9 + 7;
    int getAns(int n, int i, int ab, int late, vector<vector<vector<int>>> &dp){
        if(i == n){
            return 1;
        }
        if(dp[i][ab][late] != -1) return dp[i][ab][late];
        int ans = 0;
        if(late < 2){
            ans = (ans + getAns(n, i+1, ab, late + 1, dp)) % mod;
        }
        if(ab == 0){
            ans = (ans + getAns(n, i+1, 1, 0, dp)) % mod;
        }
        ans = (ans + getAns(n, i+1, ab, 0, dp)) % mod;
        return dp[i][ab][late] = ans;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return getAns(n, 0, 0, 0, dp);
    }
};