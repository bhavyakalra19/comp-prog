class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int,int> mp;
        for(auto f : forbidden){
            mp[f] = 1;
        }
        vector<vector<int>> visit(2,vector<int>(6002));
        visit[0][0] = 1;
        visit[1][0] = 1;
        queue<pair<int,int>> q;
        int step = 0;
        q.push({0,0});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                if(it.first == x){
                    return step;
                }
                int bck = it.first - b;
                int frw = it.first + a;
                if(frw < 6002 && mp.find(frw) == mp.end() && visit[0][frw] == 0){
                    visit[0][frw] = 1;
                    q.push({frw, 0});
                }
                if((bck >= 0) && it.second == 0 && mp.find(bck) == mp.end() && visit[1][bck] == 0){
                    visit[1][bck] = 1;
                    q.push({bck, 1});
                }
                
            }
            step++;
        }
        return -1;
    }
};