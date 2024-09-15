class Solution {
    #define ll long long

public:
    // int n;
    // vector<vector<long long>> dp;
    // long long getAns(vector<int> a, vector<int> b, int i, int j){
    //     if(i == 4){
    //         return 0;
    //     }
    //     if(dp[i][j] != INT_MIN){
    //         return dp[i][j];
    //     }
    //     if((3 - i) == (n - j - 1)){
    //         return dp[i][j] = (long long)a[i] * (long long)b[j]  + getAns(a,b,i+1,j+1);
    //     }
    //     return dp[i][j] = max((long long)a[i] * (long long)b[j] + getAns(a,b,i+1,j+1),getAns(a,b,i,j+1));
    // }

    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<ll>> dp(n+1, vector<ll> (5, LONG_MIN));
        for(int aidx = 0; aidx <= 3; aidx++) dp[n][aidx] = -1e18;
        for(int bidx = 0; bidx <= n; bidx++) dp[bidx][4] = 0;
        for(int bidx = n-1; bidx >= 0; bidx--){
            for(int aidx = 3; aidx >= 0; aidx--){
                ll take = (ll)a[aidx]*b[bidx] + dp[bidx+1][aidx+1];
                ll notTake = dp[bidx+1][aidx];
                dp[bidx][aidx] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};