class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({health - grid[0][0], {0, 0}});

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        vector<vector<int>> check(n, vector<int>(m, 0));
        check[0][0] = health - grid[0][0];

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cw = it.first;
            int cx = it.second.first;
            int cy = it.second.second;

            if(cw != check[cx][cy]) continue;

            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx < n && ny < m && nx >= 0 && ny >= 0){
                    int nw = cw - grid[nx][ny];
                    
                    if(nx == n-1 && ny == m-1 && nw != 0) return true;
                    if(nw != 0 && check[nx][ny] < nw){
                        check[nx][ny] = nw;
                        pq.push({nw, {nx, ny}});
                    }
                }
            }
        }
        return false;
    }
};