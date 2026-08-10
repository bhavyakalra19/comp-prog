class Solution {
public:

    bool getAns(int n, vector<int> &dp){
        int x = sqrt(n);
        if(x * x == n){
            return true;
        }
        if(dp[n] != -1) return dp[n];
        for(int i = 1; i * i <= n; i++){
            if(!getAns(n - i * i, dp)){
                return dp[n] = true;
            }
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1);
        return getAns(n, dp);
    }
};