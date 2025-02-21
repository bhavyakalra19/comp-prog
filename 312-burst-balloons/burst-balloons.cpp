class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(i > j){
                    continue;
                }
                int a = (i - 1 < 0) ? 1 : nums[i-1];
                int b = (j + 1 >= n) ? 1 : nums[j+1];
                int ans = INT_MIN;
                for(int k = i; k <= j; k++){
                    if(k + 1 == n && k - 1 < 0){
                        ans = max(ans, a * b * nums[k] + 0 + 0);
                    }else if(k - 1 < 0){
                        ans = max(ans, a * b * nums[k] + 0 + dp[k+1][j]);
                    }else if(k + 1 == n){
                        ans = max(ans, a * b * nums[k] + dp[i][k-1] + 0);
                    }else{
                        ans = max(ans, a * b * nums[k] + dp[i][k-1] + dp[k+1][j]);
                    }
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
    }
};