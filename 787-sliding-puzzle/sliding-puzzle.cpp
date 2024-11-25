class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string,int> mp;
        string br = "";
        string ans = "123450";
        queue<string> q;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                br += to_string(board[i][j]);
            }
        }
        mp[br] = 1;
        vector<vector<int>> steps{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        q.push(br);
        int step = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                if(it == ans){
                    return step;
                }
                int ch = 0;
                while(it[ch] != '0'){
                    ch++;
                }
                for(auto a : steps[ch]){
                    string next = it;
                    swap(next[ch],next[a]);
                    if(mp.find(next) == mp.end()){
                        mp[next] = 1;
                        q.push(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};