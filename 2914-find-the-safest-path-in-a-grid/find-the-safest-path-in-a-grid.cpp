class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {-1, 0, 1, 0};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        int curr = 2;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                int a = it.first;
                int b = it.second;

                for(int c = 0; c < 4; c++){
                    int nx = a + dx[c];
                    int ny = b + dy[c];
                    if(nx < n && ny < m && nx >= 0 && ny >= 0 && grid[nx][ny] == 0){
                        grid[nx][ny] = curr;
                        q.push({nx, ny});
                    }
                }
            }
            curr++;
        }

        vector<vector<int>> check(n, vector<int>(m, 0));
        check[0][0] = grid[0][0];
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({check[0][0], {0, 0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int cw = it.first;
            int cx = it.second.first;
            int cy = it.second.second;

            if(cx == n-1 && cy == m-1) return cw - 1;

            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx < n && ny < m && nx >= 0 && ny >= 0){
                    int nw = min(cw, grid[nx][ny]);
                    if(check[nx][ny] < nw){
                        check[nx][ny] = nw;
                        pq.push({nw, {nx, ny}});
                    }
                }
            }
        }



        
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return 4;
    }
};
