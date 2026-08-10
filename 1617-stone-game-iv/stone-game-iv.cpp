class Solution {
public:

    bool getAns(int n, vector<int> &dp){
        int x = sqrt(n);
        if(x * x == n){
            return true;
        }
        if(dp[n] != -1) return dp[n];
        bool ans = false;
        for(int i = 1; i * i <= n; i++){
            if(!getAns(n - i * i, dp)){
                ans = true;
            }
        }

        return dp[n] = ans;
    }

    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1);
        return getAns(n, dp);
    }
};