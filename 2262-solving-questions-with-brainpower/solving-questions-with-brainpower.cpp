class Solution {
public:
    long long getAns(vector<vector<int>> &nums, int idx, vector<long long> &dp){
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = max(1LL * nums[idx][0] + getAns(nums, idx + nums[idx][1] + 1, dp), getAns(nums, idx + 1, dp));
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return getAns(questions, 0, dp);
    }
};