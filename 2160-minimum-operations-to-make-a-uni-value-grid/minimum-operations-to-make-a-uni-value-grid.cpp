class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int rem = grid[0][0] % x;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(rem != grid[i][j] % x) return -1;
                ans.push_back(grid[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        if(ans.size() == 1) return 0;
        n = m * n;
        int a = ans[n/2 - 1];
        int b = ans[(n/2)];
        int ans1 = 0;
        int ans2 = 0;
        for(int i = 0; i < n; i++){
            ans1 += abs(a - ans[i]) / x;
            ans2 += abs(b - ans[i]) / x;
        }
        return min(ans1, ans2);
    }
};