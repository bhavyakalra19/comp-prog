class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> check(n, vector<int>(m, INT_MAX));
        check[0][0] = 0;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {-1,0,1,0};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cw = it.first;
            int cx = it.second.first;
            int cy = it.second.second;
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int nw = moveTime[nx][ny];
                    if((max(nw, cw) + 1) < check[nx][ny]){
                        check[nx][ny] = max(nw, cw) + 1;
                        pq.push({check[nx][ny],{nx, ny}});
                    }
                }
            }
        }
        return check[n-1][m-1];
    }
};