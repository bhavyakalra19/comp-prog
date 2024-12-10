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
        vector<int> dp(cost.size() + 1, -1);
        return getAns(cost, cost.size(), dp);
    }
};