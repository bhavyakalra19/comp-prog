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
            dp = vector<vector<long long>>(4, vector<long long>(b.size(), INT_MIN));
            return dfs(0, 0, a, b);
        }
};