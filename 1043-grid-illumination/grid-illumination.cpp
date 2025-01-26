class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> row, col, pd, nd;
        set<pair<int,int>> st;
        for(auto l : lamps){
            int x = l[0];
            int y = l[1];
            if(st.find({x,y}) == st.end()){
                st.insert({x,y});
                row[x]++;
                col[y]++;
                pd[x + y]++;
                nd[x - y]++;
            }
        }
        vector<int> ans;
        for(auto l : queries){
            int x = l[0];
            int y = l[1];
            if(row[x] != 0 || col[y] != 0 || pd[x + y] != 0 || nd[x - y] != 0){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int nx = x + i;
                    int ny = y + j;
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if(st.find({nx, ny}) != st.end()){
                        st.erase({nx, ny});
                        row[nx]--;
                        col[ny]--;
                        pd[nx + ny]--;
                        nd[nx - ny]--;
                    }
                }
            }
        }
        return ans;
    }
};