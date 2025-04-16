class Solution {
public:
    int getAns(vector<int> &nums, int st, int en, vector<vector<int>> &dp){
        if(st > en){
            return 0;
        }
        if(dp[st][en] != -1) return dp[st][en];
        int a = st - 1 < 0 ? 1 : nums[st-1];
        int b = en + 1 == nums.size() ? 1 : nums[en + 1];
        int ans = INT_MIN;
        for(int i = st; i <= en; i++){
            ans = max(ans, (a * b * nums[i]) + getAns(nums, st, i - 1, dp) + getAns(nums, i + 1, en, dp));
        }
        return dp[st][en] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return getAns(nums, 0, n-1, dp);
    }
};