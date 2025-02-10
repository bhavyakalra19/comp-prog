class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int idx = 0; idx < n; idx++){
            vector<int> check;
            int j = 0;
            int i = idx;
            while(i < n && j < n){
                check.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(check.begin(), check.end(), greater<int>());
            j = 0;
            i = idx;
            int k = 0;
            while(i < n && j < n){
                grid[i][j] = check[k];
                i++;
                j++;
                k++;
            }
        }
        for(int idx = 1; idx < n; idx++){
            vector<int> check;
            int i = 0;
            int j = idx;
            while(i < n && j < n){
                check.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(check.begin(), check.end());
            i = 0;
            j = idx;
            int k = 0;
            while(i < n && j < n){
                grid[i][j] = check[k];
                i++;
                j++;
                k++;
            }
        }
        return grid;
    }
};