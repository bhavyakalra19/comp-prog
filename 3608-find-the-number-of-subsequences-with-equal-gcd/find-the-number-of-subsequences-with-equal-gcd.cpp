class Solution {
public:
    int mod = 1e9 + 7;
    int getAns(vector<int> &nums, int gc1, int gc2, int i, int &n, vector<vector<vector<int>>> &dp){
        if(i == n){
            if(gc1 != 0 && gc1 == gc2){
                return 1;
            }
            return 0;
        }
        if(dp[gc1][gc2][i] != -1) return dp[gc1][gc2][i];
        int a = getAns(nums, gc1, gc2, i+1, n, dp);
        a = (a + getAns(nums, gcd(nums[i], gc1), gc2, i+1, n, dp)) % mod;
        a = (a + getAns(nums, gc1, gcd(nums[i], gc2), i+1, n, dp)) % mod;
        return dp[gc1][gc2][i] = a;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(auto &a : nums) mx = max(mx, a);
        vector<vector<vector<int>>> dp(mx + 1, vector<vector<int>>(mx + 1, vector<int>(n, -1)));
        return getAns(nums, 0, 0, 0, n, dp);
    }
};