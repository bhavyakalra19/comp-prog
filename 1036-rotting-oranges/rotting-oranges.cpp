class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        if(cnt == 0) return 0;
        int ans = 0;
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,-1,0,1};
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size--){
                auto it = q.front();
                q.pop();
                int cx = it.first;
                int cy = it.second;
                for(int i = 0; i < 4; i++){
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){
                        cnt--;
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return cnt == 0 ? ans - 1 : -1;
    }
};