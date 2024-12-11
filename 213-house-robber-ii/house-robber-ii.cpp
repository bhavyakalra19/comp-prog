class Solution {
public:
    int getAns(vector<int> &nums, int fi, int idx, vector<int> &dp){
        if(idx == fi){
            return nums[idx];
        }
        if(idx < fi){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        return dp[idx] = max(nums[idx] + getAns(nums,fi,idx-2,dp), getAns(nums,fi,idx-1,dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3){
            return *max_element(nums.begin(), nums.end());
        }
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        return max(getAns(nums,0,n-2,dp1), getAns(nums,1,n-1,dp2));
    }
};