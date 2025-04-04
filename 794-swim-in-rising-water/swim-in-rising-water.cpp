class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> check(n, vector<int>(m,INT_MAX));
        pq.push({grid[0][0], {0,0}});
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        check[0][0] = grid[0][0];
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cw = it.first;
            int cx = it.second.first;
            int cy = it.second.second;
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 & ny < m && max(cw, grid[nx][ny]) < check[nx][ny]){
                    check[nx][ny] = max(cw, grid[nx][ny]);
                    pq.push({check[nx][ny], {nx, ny}});
                }
            }
        }
        return check[n-1][m-1];
    }
};