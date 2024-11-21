class Solution {
public:
    void getAns(vector<vector<int>> &check, int m, int n, int x, int y, int &ans){
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        for(int i = 0; i < 4; i++){
            int nx = x;
            int ny = y;
            while(1){
                nx += dx[i];
                ny += dy[i];
                if(nx >= m || nx < 0 || ny >= n || ny < 0 || check[nx][ny] == 1){
                    break;
                }
                if(check[nx][ny] == 0){
                    ans += 1;
                }
                check[nx][ny] = 2;
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> check(m,vector<int>(n,0));
        int ans = 0;
        for(auto g : guards){
            ans += 1;
            check[g[0]][g[1]] = 1;
        }
        for(auto w : walls){
            ans += 1;
            check[w[0]][w[1]] = 1;
        }
        for(auto g : guards){
            getAns(check,m,n,g[0],g[1],ans);
        }
        return m*n - ans;
    }
};