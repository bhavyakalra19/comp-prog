class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> count(m,0);
        vector<int> check(m,0);
        int rc = 0;
        int ls = -1;
        int ts = 0;
        for(int i = 0; i < n; i++){
            rc = 0;
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    count[j] += 1;
                    ls = j;
                    rc++;
                    ts++;
                }
            }
            if(rc == 1){
                check[ls] = 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            if(check[i] == 1 && count[i] == 1){
                ans += 1;
            }
        }
        return ts - ans;
    }
};