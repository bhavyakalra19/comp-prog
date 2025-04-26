class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m,-1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 0;
                }
            }
        }
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        int val = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                int cx = it.first;
                int cy = it.second;
                for(int i = 0; i < 4; i++){
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    if(nx < n && nx >= 0 && ny < m && ny >= 0 && vis[nx][ny] == -1){
                        vis[nx][ny] = val;
                        q.push({nx,ny});
                    }
                }
            }
            val++;
        }
        return vis;
    }
};