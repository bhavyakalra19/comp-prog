class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        int d = 0;
        int ans = 0;
        unordered_map<int,unordered_set<int>> mp;
        for(int i = 0; i < obstacles.size(); i++){
            mp[obstacles[i][0]].insert(obstacles[i][1]);
        }
        int x = 0;
        int y = 0;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(int i = 0; i < n; i++){
            if(commands[i] == -1){
                d = (d+1)%4;
            }else if(commands[i] == -2){
                d = (d+3)%4;
            }else{
                for(int j = 1; j <= commands[i]; j++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(mp.find(nx) != mp.end() && mp[nx].find(ny) != mp[nx].end()){
                        break;
                    }
                    x = nx;
                    y = ny;
                    ans = max(ans,x*x + y*y);
                }
            }
        }
        return ans;
    }
};
