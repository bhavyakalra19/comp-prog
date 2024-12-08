class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n,INT_MIN);
        long long window = 0;
        long long mx = INT_MIN;
        for(int i = 0; i < n; i++){
            window += nums[i];
            if(i >= k - 1){
                if(i == k-1){
                    dp[i] = window;
                    mx = window;
                }else{
                    dp[i] = max(window + dp[i - k], window);
                    mx = max(dp[i],mx);
                }
                window -= nums[i-k+1];
            }
        }
        return mx;
    }
};



