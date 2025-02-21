class Solution {
public:
    int n;
    int getAns(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        int a = (i-1 < 0) ? 1 : nums[i-1];
        int b = (j+1 > n) ? 1 : nums[j+1];
        for(int k = i; k <= j; k++){
            ans = max(ans, (a * b * nums[k]) + getAns(nums, i, k-1, dp) + getAns(nums, k+1, j, dp));
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        n = nums.size() - 1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return getAns(nums, 0, n, dp);
    }
};
