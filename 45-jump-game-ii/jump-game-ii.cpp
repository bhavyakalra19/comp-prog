class Solution {
public:
    int getAns(vector<int> &nums, int idx, vector<int> &dp){
        if(idx >= nums.size() - 1){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int ans = 100000;
        for(int i = 1; i <= nums[idx]; i++){
            ans = min(ans, getAns(nums,idx + i, dp));
        }
        return dp[idx] = 1 + ans;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return getAns(nums,0,dp);
    }
};