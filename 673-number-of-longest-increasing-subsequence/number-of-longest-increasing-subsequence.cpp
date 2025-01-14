class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int mx = 1;
        int mxCount = 0;
        vector<int> count(n,1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    mx = max(mx, dp[i]);
                    count[i] = count[j];
                }else if(nums[i] > nums[j] && dp[i] == dp[j] + 1){
                    count[i] += count[j];
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == mx){
                cnt += count[i];
            }
        }
        return cnt;
    }
};