class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> check(n, vector<int>(n, INT_MAX));
        check[0][0] = grid[0][0];
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        int dx[4] = {0,-1,0,1};
        int dy[4] = {1,0,-1,0};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cw = it.first;
            int cx = it.second.first;
            int cy = it.second.second;
            if(cx == n-1 && cy == n-1) return cw;
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && max(cw, grid[nx][ny]) < check[nx][ny]){
                    int nw = max(cw, grid[nx][ny]);
                    check[nx][ny] = nw;
                    pq.push({nw, {nx, ny}});
                }
            }
        }
        return -1;
    }
};