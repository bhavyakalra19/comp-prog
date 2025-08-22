class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int li = n;
        int mi = 0;
        int lj = m;
        int mj = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    li = min(li, i);
                    mi = max(mi, i);
                    lj = min(lj, j);
                    mj = max(mj, j);
                }
            }
        }
        return (mi - li + 1) * (mj - lj + 1);
    }
};