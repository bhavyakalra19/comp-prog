class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> ans(m,vector<char>(n));
        for(int i = n-1; i >= 0; i--){
            int prev = m - 1;
            for(int j = m-1; j >= 0; j--){
                if(box[i][j] == '*'){
                    prev = j - 1;
                }else if(box[i][j] == '#'){
                    box[i][j] = '.';
                    box[i][prev] = '#';
                    prev -= 1;
                }
            }
            for(int j = 0; j < m; j++){
                ans[j][n - i - 1] = box[i][j];
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         ans[j][n - i - 1] = box[i][j];
        //     }
        // }
        return ans;
    }
};