class Solution {
public:
    // int getAns(vector<int> &cost, int n){
    //     if(n < 0){
    //         return 0;
    //     }
    //     if(n == 0 || n == 1){
    //         return cost[n];
    //     }
    //     return cost[n] + min(getAns(cost, n-1), getAns(cost, n-2));
    // }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev1 = cost[1];
        int prev2 = cost[0];
        int curr;
        for(int i = 2; i < n; i++){
            curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }
};