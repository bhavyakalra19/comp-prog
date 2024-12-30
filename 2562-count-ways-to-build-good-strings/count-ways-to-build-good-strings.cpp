class Solution {
public:
    const int mod = 1e9 + 7;
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
