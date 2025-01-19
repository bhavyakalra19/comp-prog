class Solution {
public:
    const int mod = 1e9 + 7;
    long long getAns(int n, int r, vector<vector<int>> &dp){
        if(r == 0){
            return 1;
        }
        if(n == 0){
            return r == 0;
        }
        if(dp[n][r] != -1){
            return dp[n][r];
        }
        long long a = getAns(n-1, r, dp);
        long long b = getAns(n-1, r-1, dp);
        return dp[n][r] = (a + b) % mod;
    }

    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(k,0));
        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < k; j++){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod;
            }
        }
        long long ans = 0;
        for(int a : nums){
            ans += 2 * a;
        }
        ans = ans % mod;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            for(int j = 1; j < k; j++){
                ans = (ans + (nums[i] * dp[n - i - 1][j] % mod)) % mod;
                ans = (ans + (nums[i] * dp[i][j]) % mod) % mod;
            }
        }
        return ans;
    }
};
