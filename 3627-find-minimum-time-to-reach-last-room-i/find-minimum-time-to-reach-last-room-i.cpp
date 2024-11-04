class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> check(m,vector<int>(n,INT_MAX));
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        pq.push({0, {0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cx = it.second.first;
            int cy = it.second.second;
            if(cx == m-1 && cy == n-1){
                return it.first;
            }
            int cw = it.first;
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx >= m || nx < 0 || ny >= n || ny < 0){
                    continue;
                }
                int nw = max(cw, moveTime[nx][ny]) + 1;
                if(nw < check[nx][ny]){
                    check[nx][ny] = nw;
                    pq.push({nw,{nx,ny}});
                }
            }
        }
        return -1;
    }
};