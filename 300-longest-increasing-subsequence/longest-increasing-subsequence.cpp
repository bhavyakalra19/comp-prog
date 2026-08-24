class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int mx = 1;
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            int curr = 0;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    curr = max(curr, dp[j]);
                }
            }
            dp[i] = curr + 1;
            mx = max(mx, dp[i]);
        }
        return mx;
    }
};