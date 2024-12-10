class Solution {
public:
    // int getAns(vector<int> &cost, int idx){
    //     if(idx <= 1){
    //         return cost[idx];
    //     }
    //     int a = getAns(cost, idx - 1);
    //     int b = getAns(cost, idx - 2);
    //     return min(a,b);
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