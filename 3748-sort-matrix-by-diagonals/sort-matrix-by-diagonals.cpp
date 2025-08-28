class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++){
            vector<int> ans;
            int a = i;
            int b = 0;
            while(a < n && b < m){
                ans.push_back(grid[a++][b++]);
            }
            sort(ans.begin(), ans.end(), greater<int>());
            a = i;
            b = 0;
            for(auto &c : ans){
                grid[a++][b++] = c;
            }
        }

        for(int j = 1; j < m; j++){
            vector<int> ans;
            int a = 0;
            int b = j;
            while(a < n && b < m){
                ans.push_back(grid[a++][b++]);
            }
            sort(ans.begin(), ans.end());
            a = 0;
            b = j;
            for(auto &c : ans){
                grid[a++][b++] = c;
            }
        }
        return grid;
    }
};