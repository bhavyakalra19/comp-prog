class Solution {
public:
    int n;
    int getAns(vector<int> &nums, int i, int check, vector<vector<int>> &dp){
        if(i >= n) return nums[check];
        if(i + 1 >= n) return max(nums[i], nums[check]);
        if(dp[i][check] != -1) return dp[i][check];
        int a = max(nums[i], nums[i+1]) + getAns(nums, i + 2, check, dp);
        int b = max(nums[i], nums[check]) + getAns(nums, i + 2, i+1, dp);
        int c = max(nums[check], nums[i+1]) + getAns(nums, i + 2, i, dp);
        return dp[i][check] = min(a,min(b,c));
    }

    int minCost(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return getAns(nums, 1, 0, dp);
    }
};