class Solution {
public:
    int getAns(vector<int> &nums, int idx, int prev, vector<vector<int>> &dp){
        if(idx == nums.size()){
            return 0;
        }
        if(dp[idx][prev+1] != -1){
            return dp[idx][prev+1];
        }
        int notTake = getAns(nums, idx + 1, prev, dp);
        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev]){
            take = 1 + getAns(nums, idx + 1, idx, dp);
        }
        return dp[idx][prev+1] = max(notTake, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = n-1; i >= 0; i--){
            for(int j = i-1; j >= -1; j--){
                int notTake = dp[i+1][j+1];
                int take = 0;
                if(j == -1 || nums[i] > nums[j]){
                    take = 1 + dp[i+1][i+1];
                }
                dp[i][j+1] = max(notTake, take);
            }
        }
        return dp[0][0];
        // return getAns(nums,0,-1,dp);
    }
};