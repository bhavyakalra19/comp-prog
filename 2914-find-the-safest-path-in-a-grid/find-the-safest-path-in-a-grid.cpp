class Solution {
public:
    int n;
    int m;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {-1, 0, 1, 0};
    

    //get score of each grid starting from all 1's
    void getGridScore(vector<vector<int>> &grid, queue<pair<int,int>> &q){
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int cx = it.first;
            int cy = it.second;
            int cw = grid[cx][cy] == -1 ? 0 : grid[cx][cy];
            for(int a = 0; a < 4; a++){
                int nx = cx + dx[a];
                int ny = cy + dy[a];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0){
                    grid[nx][ny] = cw + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int applyDijkstraAlgo(vector<vector<int>> &grid){
        queue<pair<int,int>> q;
        vector<vector<int>> check(n, vector<int>(m, -1));
        check[0][0] = grid[0][0];
        q.push({0, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int cx = it.first;
            int cy = it.second;
            int cw = check[cx][cy];
            for(int a = 0; a < 4; a++){
                int nx = cx + dx[a];
                int ny = cy + dy[a];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int nw = min(grid[nx][ny], cw);
                    if(check[nx][ny] < nw){
                        q.push({nx, ny});
                        check[nx][ny] = nw;
                    }
                }
            }
        }
        return check[n-1][m-1];
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    grid[i][j] = -1;
                    q.push({i, j});
                }
            }
        }
        
        getGridScore(grid, q);
        
        //apply dijkstra
        int ans = applyDijkstraAlgo(grid);
        return ans == -1 ? 0 : ans;
    }
};