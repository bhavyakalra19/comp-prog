class Solution {
public:
    int n;
    int getAns(int st, int en, vector<int> &nums, vector<vector<int>> &dp){
        if(st > en) return 0;
        if(dp[st][en] != -1) return dp[st][en];
        int left = (st == 0 ? 1 : nums[st - 1]);
        int right = (en == n - 1 ? 1 : nums[en + 1]);
        int ans = INT_MIN;
        for(int i = st; i <= en; i++){
            ans = max(ans, left * right * nums[i] + getAns(st, i-1, nums, dp) + getAns(i+1, en, nums, dp));
        }
        return dp[st][en] = ans;
    }

    int maxCoins(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n, -1));
        return getAns(0, n-1, nums, dp);
    }
};