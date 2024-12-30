class Solution {
public:
    // int getAns(vector<int> &nums, int idx, vector<int> &dp){
    //     if(idx == 0){
    //         return nums[0];
    //     }
    //     if(idx == 1){
    //         return max(nums[0],nums[1]);
    //     }
    //     if(dp[idx] != -1){
    //         return dp[idx];
    //     }
    //     int notTake = getAns(nums, idx-1,dp);
    //     int take = nums[idx] + getAns(nums,idx-2,dp);
    //     return dp[idx] = max(take,notTake);
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        if(n == 1){
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[n-1];
        // return getAns(nums,n-1,dp);
    }
};