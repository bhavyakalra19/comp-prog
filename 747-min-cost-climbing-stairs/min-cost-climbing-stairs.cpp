class Solution {
public:
    int getAns(vector<int> &cost, int n){
        if(n < 0){
            return 0;
        }
        if(n == 0 || n == 1){
            return cost[n];
        }
        return cost[n] + min(getAns(cost, n-1), getAns(cost, n-2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};