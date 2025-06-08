class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();
        int trash = 0;
        int x = 0;
        int y = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(classroom[i][j] == 'L'){
                    classroom[i][j] = '0' + trash;
                    trash++;
                }else if(classroom[i][j] == 'S'){
                    x = i;
                    y = j;
                }
            }
        }
        if(trash == 0) return 0;
        int mx = (1 << trash) - 1;
        vector<vector<vector<int>>> check(n, vector<vector<int>>(m, vector<int>(mx + 1, -1)));
        check[x][y][0] = energy;
        int ans = INT_MAX;
        queue<vector<int>> q;
        q.push({x, y, energy, 0, 0});
        int dx[4] = {0,1,0,-1};
        int dy[4] = {-1,0,1,0};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int cx = it[0];
            int cy = it[1];
            int ce = it[2];
            int cm = it[3];
            int cs = it[4];
            if(cm == mx) return cs;
            if(ce == 0 && classroom[cx][cy] != 'R') continue;
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                int ne = ce - 1;
                int nm = cm;
                if(nx < 0 || nx == n || ny < 0 || ny == m || classroom[nx][ny] == 'X') continue;
                if(classroom[nx][ny] == 'R'){
                    ne = energy;
                }else if(classroom[nx][ny] != '.' && classroom[nx][ny] != 'S'){
                    int num = classroom[nx][ny] - '0';
                    nm = nm | (1 << num);
                }
                if(check[nx][ny][nm] < ne){
                    check[nx][ny][nm] = ne;
                    q.push({nx, ny, ne, nm, cs + 1});
                }
            }
        }
        return -1;
    }
};