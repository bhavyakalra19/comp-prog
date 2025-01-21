class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> top(n, 0);
        vector<long long> down(n, 0);
        long long ts = 0;
        long long ds = 0;
        for(int i = 0; i < n; i++){
            ts += grid[0][i];
            ds += grid[1][n-1-i];
            top[i] = ts;
            down[n-i-1] = ds;
        }
        long long ans = LONG_MAX;
        long long mx = 0;
        for(int i = 0; i < n; i++){
            ans = min(ans, max(ts - top[i], ds - down[i]));
        }
        return ans;
    }
};

