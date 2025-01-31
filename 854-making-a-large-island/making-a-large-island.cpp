class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int,int> mp;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {-1,0,1,0};
        vector<vector<int>> vis(n,vector<int>(n,-1));
        int mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] && vis[i][j] == -1){
                    queue<pair<int,int>> q;
                    int a = (n * i) + j;
                    q.push({i,j});
                    vis[i][j] = a;
                    int cnt = 1;
                    while(!q.empty()){
                        auto it = q.front();
                        q.pop();
                        int cx = it.first;
                        int cy = it.second;
                        for(int idx = 0; idx < 4; idx++){
                            int nx = cx + dx[idx];
                            int ny = cy + dy[idx];
                            if(nx < n && ny < n && nx >= 0 && ny >= 0 && vis[nx][ny] == -1 && grid[nx][ny] == 1){
                                vis[nx][ny] = a;
                                cnt++;
                                q.push({nx,ny});
                            }
                        }
                    }
                    mp[a] = cnt;
                    mx = max(mx, cnt);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> st;
                    int cnt = 0;
                    for(int idx = 0; idx < 4; idx++){
                        int nx = i + dx[idx];
                        int ny = j + dy[idx];
                        if(nx < n && ny < n && nx >= 0 && ny >= 0 && grid[nx][ny]){
                            int a = vis[nx][ny];
                            if(st.find(a) == st.end()){
                                st.insert(a);
                                cnt += mp[a];
                            }
                        }
                    }
                    mx = max(mx, cnt + 1);
                }
            }
        }
        return mx;
    }
};