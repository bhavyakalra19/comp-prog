class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> check(n,vector<int>(m,INT_MAX));
        check[0][0] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cx = it.second.first;
            int cy = it.second.second;
            int cw = it.first;
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx < n && ny < m && nx >= 0 && ny >= 0){
                    int nw = cw + 1;
                    if((grid[cx][cy] == 1) && (nx == cx) && (ny == cy + 1)){
                        nw = cw;
                    }else if((grid[cx][cy] == 2) && (nx == cx) && (ny == cy - 1)){
                        nw = cw;
                    }else if((grid[cx][cy] == 3) && (nx == cx + 1) && (ny == cy)){
                        nw = cw;
                    }else if((grid[cx][cy] == 4) && (nx == cx - 1) && (ny == cy)){
                        nw = cw;
                    }
                    if(check[nx][ny] > nw){
                        check[nx][ny] = nw;
                        pq.push({nw,{nx,ny}});
                    }
                }
            }
        }
        return check[n-1][m-1];
    }
};