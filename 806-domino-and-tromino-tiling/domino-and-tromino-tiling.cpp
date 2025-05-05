class Solution {
public:
    const int mod = 1e9 + 7;
    long getAns(int idx, int n, bool space, vector<vector<long>> &dp){
        if(idx == n){
            return space == false;
        }
        if(idx > n) return 0;
        if(dp[idx][space] != -1) return dp[idx][space];
        long ans = 0;
        if(space){
            return dp[idx][space] = (getAns(idx + 1, n, true, dp) + getAns(idx + 1, n, false, dp)) % mod;
        }
        ans = getAns(idx + 1, n, false, dp);
        ans = (ans + getAns(idx + 2, n, false, dp)) % mod;
        ans = (ans + (2 * getAns(idx + 2, n, true, dp))) % mod;
        return dp[idx][space] = ans;
    }

    int numTilings(int n) {
        vector<vector<long>> dp(n, vector<long>(2, -1));
        return getAns(0, n, false, dp);
    }
};



