class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        vector<vector<int>> check(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cw = it.first;
            int cx = it.second.first;
            int cy = it.second.second;
            if(cx == n - 1 && cy == m - 1){
                return check[cx][cy];
            }
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx < n && nx >= 0 && ny < m && ny >= 0 && check[nx][ny] > grid[nx][ny] + cw){
                    check[nx][ny] = grid[nx][ny] + cw;
                    pq.push({grid[nx][ny] + cw,{nx,ny}});
                }
            }
        }
        return check[n-1][m-1];
    }
};