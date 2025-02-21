class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2,0));
        for(int i = n; i >= 1; i--){
            for(int j = 1; j <= n; j++){
                if(i > j){
                    continue;
                }
                int a = (i - 2 < 0) ? 1 : nums[i-2];
                int b = (j >= n) ? 1 : nums[j];
                int ans = INT_MIN;
                for(int k = i; k <= j; k++){
                    ans = max(ans, a * b * nums[k-1] + dp[i][k-1] + dp[k+1][j]);

                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
};