class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> gp{{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2, 4}};
        unordered_set<string> mp;
        string main = "123450";
        string check = "";
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                check += to_string(board[i][j]);
            }
        }
        if(check == main) return 0;
        queue<string> q;
        q.push(check);
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size--){
                auto it = q.front();
                q.pop();
                int idx = 0;
                while(it[idx] != '0') idx++;
                for(auto &a : gp[idx]){
                    string str = it;
                    swap(str[idx], str[a]);
                    if(str == main) return ans;
                    if(mp.find(str) == mp.end()){
                        q.push(str);
                        mp.insert(str);
                    }
                }
            }
        }
        return -1;
    }
};