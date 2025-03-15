class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0], {0,0}});
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,-1,0,1};
        vector<vector<bool>> visit(n,vector<bool>(m,0));
        visit[0][0] = true;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cx = it.second.first;
            int cy = it.second.second;
            int cw = it.first;
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx == n-1 && ny == m-1) return max(cw, grid[nx][ny]);
                if(nx < n && nx >= 0 && ny < m && ny >= 0 && !visit[nx][ny]){
                    visit[nx][ny] = true;
                    pq.push({max(cw, grid[nx][ny]), {nx, ny}});
                }
            }
        }
        return 0;
    }
};