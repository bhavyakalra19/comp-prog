class Solution {
public:
    // int getAns(int n, vector<int> &dp){
    //     if(n <= 1){
    //         return n;
    //     }
    //     if(dp[n] != -1){
    //         return dp[n];
    //     }
    //     return dp[n] = getAns(n-1,dp) + getAns(n-2,dp);
    // }

    int fib(int n) {
        // vector<int> dp(n+1,-1);
        // dp[0] = 0;
        // dp[1] = 1;
        // for(int i = 2; i <= n; i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];
        int prev1 = 1;
        int prev2 = 0;
        int curr = 0;
        if(n <= 1){
            return n;
        }
        for(int i = 2; i <= n; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};