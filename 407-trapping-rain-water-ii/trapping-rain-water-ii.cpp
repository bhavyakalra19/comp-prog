class Solution {
public:
    int trapRainWater(vector<vector<int>>& hm) {
        int n = hm.size();
        int m = hm[0].size();
        vector<vector<int>> vis(n,vector<int>(m,false));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        for(int i = 0; i < n; i++){
            if(i == 0 || i == n - 1){
                for(int j = 0; j < m; j++){
                    pq.push({hm[i][j],{i,j}});
                    vis[i][j] = true;
                }
            }else{
                pq.push({hm[i][0], {i,0}});
                vis[i][0] = true;
                if(m > 1){
                    pq.push({hm[i][m-1], {i,m-1}});
                    vis[i][m-1] = true;
                }
            }
        }
        int ans = 0;
        int dx[4] = {-1, 0 ,1, 0};
        int dy[4] = {0 , 1, 0, -1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int ch = it.first;
            int cx = it.second.first;
            int cy = it.second.second;
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx < 0 || nx == n || ny < 0 || ny == m || vis[nx][ny] == true){
                    continue;
                }
                vis[nx][ny] = true;
                ans += max(0, ch - hm[nx][ny]);
                int nh = max(hm[nx][ny],ch);
                pq.push({nh,{nx,ny}});
            }
        }
        return ans;
    }
};