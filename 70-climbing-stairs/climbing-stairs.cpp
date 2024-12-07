class Solution {
public:
    int climbStairs(int num) {
        // vector<int> dp(num+1, -1);
        // dp[0] = 1;
        // dp[1] = 1;
        int prev1 = 1;
        int prev2 = 1;
        int curr = 1;
        for(int i = 2; i <= num; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};