class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int mx = 1;
        for(int i = 1; i < n; i++){
            int ans = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    ans = max(ans, dp[j]);
                }
            }
            dp[i] = ans + 1;
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};