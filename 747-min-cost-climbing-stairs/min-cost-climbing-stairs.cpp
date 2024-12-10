 class Solution {
public:
    int getAns(vector<int> &cost, int idx, vector<int> &dp){
        if(idx <= 1){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int a = cost[idx - 1] + getAns(cost, idx - 1,dp);
        int b = cost[idx - 2] + getAns(cost, idx - 2,dp);
        return dp[idx] = min(a,b);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(cost.size() + 1, -1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= n; i++){
            dp[i] = min(cost[i-1] + dp[i - 1], cost[i-2] + dp[i-2]);
        }
        return dp[n];
    }
};