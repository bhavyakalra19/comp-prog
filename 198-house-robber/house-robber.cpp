class Solution {
public:
    int getAns(vector<int> &nums, int idx, vector<int> &dp){
        if(idx == 0){
            return nums[0];
        }
        if(idx == 1){
            return max(nums[0],nums[1]);
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int notTake = getAns(nums, idx-1,dp);
        int take = nums[idx] + getAns(nums,idx-2,dp);
        return dp[idx] = max(take,notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        // for(int i = 0; i < n; i++){
        //     int 
        // }
        return getAns(nums,n-1,dp);
    }
};