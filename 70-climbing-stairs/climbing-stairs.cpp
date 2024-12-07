class Solution {
public:
    int climbStairs(int num) {
        vector<int> dp(num+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= num; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[num];
    }
};