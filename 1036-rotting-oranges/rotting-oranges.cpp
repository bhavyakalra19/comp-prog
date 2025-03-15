class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {1, 0, -1, 0};
        int ans = 0;
        int cnt = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) cnt += 1;
            }
        }
        if(cnt == 0) return 0;
        while(!q.empty()){
            ans++;
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                int cx = it.first;
                int cy = it.second;
                grid[cx][cy] = 0;
                for(int i = 0; i < 4; i++){
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    if(nx < n && nx >= 0 && ny < m && ny >= 0 && grid[nx][ny] == 1){
                        cnt--;
                        if(cnt == 0) return ans;
                        grid[nx][ny] = 0;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};