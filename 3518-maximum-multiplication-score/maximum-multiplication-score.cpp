class Solution {
    public:
        vector<vector<long long>> dp;
        long long dfs(int i, int j, vector<int>& a, vector<int>& b) {
            if (i >= a.size() || j >= b.size())
                return i == a.size() ? 0 : INT_MIN;
            if (dp[i][j] == INT_MIN)
                dp[i][j] = max(dfs(i, j + 1, a, b), 
                            (long long)a[i] * b[j] + dfs(i + 1, j + 1, a, b));
            return dp[i][j];
        } 
        long long maxScore(vector<int>& a, vector<int>& b) {
            // dp = vector<vector<long long>>(5, vector<long long>(b.size() + 1, INT_MIN));
            // return dfs(0, 0, a, b);
            int n = b.size();
            dp = vector<vector<long long>>(5,vector<long long>(n+1,LONG_MIN));
            for(int i = 0; i < 5; i++){
                dp[i][0] = -1e11;
            }
            for(int i = 0; i <= n; i++){
                dp[0][i] = 0;
            }
            for(int i = 1; i < 5; i++){
                for(int j = 1; j <= n; j++){
                    long long take = (long long)(a[i-1]) * (long long)(b[j-1]) + dp[i-1][j-1];
                    long long notTake = dp[i][j-1];
                    dp[i][j] = max(take, notTake);
                }
            }
            return dp[4][n];
        }
};