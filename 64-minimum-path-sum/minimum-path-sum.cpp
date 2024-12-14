class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,0);
        for(int i = 0; i < m; i++){
            vector<int> curr(n,0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    curr[j] = grid[i][j];
                }else{
                    int a = i > 0 ? prev[j] : INT_MAX;
                    int b = j > 0 ? curr[j-1] : INT_MAX;
                    curr[j] = grid[i][j] + min(a,b);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};