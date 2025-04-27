class Solution {
public:
    int getAns(vector<vector<int>> &nums, int idx, int prev, vector<vector<int>> &dp){
        if(idx == nums.size()){
            return 0;
        }
        if(dp[idx][prev] != -1) return dp[idx][prev];
        int take = 0;
        if(prev == nums.size() || ((nums[idx][0] >= nums[prev][0]) && (nums[idx][1] >= nums[prev][1]) && (nums[idx][2] >= nums[prev][2]))){
            take = nums[idx][2] + getAns(nums, idx + 1, idx, dp);
        }
        return dp[idx][prev] = max(take, getAns(nums, idx + 1, prev, dp));
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(auto &a : cuboids){
            sort(a.begin(), a.end());
        }
        sort(cuboids.begin(), cuboids.end());
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return getAns(cuboids, 0, n, dp);
    }
};
