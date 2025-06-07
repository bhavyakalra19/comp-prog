class Solution {
public:
    int getAns(vector<vector<int>> &grid, int n, int m, int k){
        vector<int> check;
        for(int i = n; i < n + k; i++){
            for(int j = m; j < m + k; j++){
                check.push_back(grid[i][j]);
            }
        }
        sort(check.begin(), check.end());
        int i = 0;
        int j = 1;
        int mx = k * k;
        int mn = INT_MAX;
        while(j < mx){
            if(check[i] != check[j]){
                mn = min(mn, check[j] - check[i]);
            }
            i++;
            j++;
        }
        if(mn == INT_MAX) return 0;
        return mn;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i <= (n - k); i++){
            vector<int> check;
            for(int j = 0; j <= (m - k); j++){
                check.push_back(getAns(grid, i, j, k));
            }
            ans.push_back(check);
        }
        return ans;
    }
};