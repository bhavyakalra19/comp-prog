class Solution {
public:
    int n;

    int getAns(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        if(i == n){
            return 0;
        }
        // skip taking 
        // taking then use newer j
        if(dp[i][j] != INT_MIN) return dp[i][j];

        int ans = getAns(nums, i+1, j, dp);
        if(j == n || nums[i] > nums[j]) ans = max(ans, 1 + getAns(nums, i+1, i, dp));
        return dp[i][j] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, INT_MIN));
        return getAns(nums, 0, n, dp);
    }
};