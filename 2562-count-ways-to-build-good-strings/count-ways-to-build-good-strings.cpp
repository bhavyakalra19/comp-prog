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
        vector<int> dp(high + 1, - 1);
        return  (getAns(zero, one, high, dp) - getAns(zero, one, low - 1, dp) + mod) % mod;
    }
};
