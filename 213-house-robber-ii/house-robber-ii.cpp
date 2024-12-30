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
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0],nums[1]);
        }
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0],nums[1]);
        for(int i = 2; i < n - 1; i++){
            dp1[i] = max(dp1[i-1], nums[i] + dp1[i-2]);
        }
        dp2[0] = 0;
        dp2[1] = nums[1];
        for(int i = 2; i < n; i++){
            dp2[i] = max(dp2[i-1], nums[i] + dp2[i-2]);
        }
        // getAns(nums,n-2,0,dp1);
        // getAns(nums,n-1,1,dp2);
        return max(dp1[n-2], dp2[n-1]);
    }
};
