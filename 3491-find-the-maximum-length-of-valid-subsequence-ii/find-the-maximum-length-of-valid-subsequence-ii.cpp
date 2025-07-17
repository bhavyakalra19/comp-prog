class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int res = 2;
        int n = nums.size();
        for(int i = 0; i < k; i++){
            vector<int> dp(k, 0);
            for(int j = 0; j < n; j++){
                int curr = nums[j] % k;
                int pos = (i - curr + k) % k;
                dp[curr] = dp[pos] + 1;
            }
            for(auto a : dp){
                res = max(res, a);
            }
        }
        return res;
    }
};
