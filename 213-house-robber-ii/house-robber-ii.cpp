class Solution {
public:
    // int getAns(vector<int> &nums, int idx, int low, vector<int> &dp){
    //     if(idx < low){
    //         return 0;
    //     }
    //     if(dp[idx] != -1){
    //         return dp[idx];
    //     }
    //     int notTake = getAns(nums, idx - 1, low, dp);
    //     int take = nums[idx] + getAns(nums, idx - 2, low, dp);
    //     return dp[idx] = max(notTake, take);
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3){
            return *max_element(nums.begin(),nums.end());
        }
        // vector<int> dp1(n,-1);
        // vector<int> dp2(n,-1);
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        for(int i = 2; i < n - 1; i++){
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        int p2 = 0;
        int p1 = nums[1];
        for(int i = 2; i < n; i++){
            int curr = max(p1, nums[i] + p2);
            p2 = p1;
            p1 = curr;
        }
        // getAns(nums,n-2,0,dp1);
        // getAns(nums,n-1,1,dp2);
        return max(prev1, p1);
    }
};
