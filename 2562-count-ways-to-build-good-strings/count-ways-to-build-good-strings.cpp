class Solution {
public:
    const int mod = 1e9 + 7;
    int getAns(int &zero, int &one, int mx, vector<int> &dp){
        if(mx < zero && mx < one){
            return 1;
        }
        if(dp[mx] != -1){
            return dp[mx];
        }
        int a = 0;
        if(mx >= zero){
            a = (a + getAns(zero, one, mx - zero, dp)) % mod;
        }
        if(mx >= one){
            a = (a + getAns(zero, one, mx - one, dp)) % mod;
        }
        return dp[mx] = (a + 1) % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        for(int i = 0; i < min(zero,one); i++){
            dp[i] = 1;
        }
        for(int i = min(one,zero); i <= high; i++){
            int a = 0;
            if(i >= zero){
                a = a + dp[i - zero];
            }
            if(i >= one){
                a = (a + dp[i - one]) % mod;
            }
            
            dp[i] = (a + 1)% mod;
        }
        return (dp[high] - dp[low - 1] + mod)%mod;
    }
};
