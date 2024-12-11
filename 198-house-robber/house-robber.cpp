class Solution {
public:
    int getAns(vector<int> &nums, int idx, int n, vector<int> &dp){
        if(idx == 0){
            return nums[idx];
        }
        if(idx < 0){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int take = nums[idx] + getAns(nums, idx - 2, n, dp);
        int notTake = getAns(nums, idx - 1, n, dp);
        return dp[idx] = max(take,notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();  
        vector<int> dp(n+1, -1);
        return getAns(nums, n-1, n, dp);  
    }
};