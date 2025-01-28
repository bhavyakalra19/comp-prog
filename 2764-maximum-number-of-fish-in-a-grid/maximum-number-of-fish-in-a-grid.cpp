class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx = 0;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0){
                    q.push({i,j});
                    int sm = grid[i][j];
                    grid[i][j] = 0;
                    while(!q.empty()){
                        auto it = q.front();
                        q.pop();
                        int cx = it.first;
                        int cy = it.second;
                        for(int a = 0; a < 4; a++){
                            int nx = cx + dx[a];
                            int ny = cy + dy[a];
                            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] > 0){
                                sm += grid[nx][ny];
                                grid[nx][ny] = 0;
                                q.push({nx,ny});
                            }
                        }
                    }
                    mx = max(mx, sm);
                }
            }
        }
        return mx;
    }
};