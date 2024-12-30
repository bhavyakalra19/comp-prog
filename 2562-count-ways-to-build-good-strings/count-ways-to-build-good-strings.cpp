class Solution {
public:
    const int mod = 1e9 + 7;
    int getAns(int &zero, int &one, int mx, vector<int> &dp){
        if(mx < one && mx < zero){
            return 1;
        }
        int a = 0;
        if(dp[mx] != -1){
            return dp[mx];
        }
        if(mx >= zero){
            a += getAns(zero, one, mx - zero, dp);
        }
        if(mx >= one){
            a = (a + getAns(zero, one, mx - one, dp)) % mod;
        }
        return dp[mx] = (a + 1)%mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1,0);
        for(int i = 0; i <= high; i++){
            if(i < one && i < zero){
                dp[i] = 1;
            }else{
                int a = 0;
                if(i >= one){
                    a = dp[i-one];
                }
                if(i >= zero){
                    a = (a + dp[i-zero])%mod;
                }
                dp[i] = (a + 1)%mod;
            }
        }
        return (dp[high] - dp[low - 1] + mod) % mod;
        // return (getAns(zero,one,high,dp)  - getAns(zero,one,low-1,dp) + mod)%mod;
    }
};