class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int total = rows * cols;
        int cal = 1;
        vector<vector<int>> ans;
        int count = 1;
        int nx;
        int ny;
        int x = rStart;
        int y = cStart;
        ans.push_back({rStart,cStart});
        vector<int> dx{0,1,0,-1};
        vector<int> dy{1,0,-1,0};
        while(1){
            rStart = 0;
            while(rStart < count){
                x = x + dx[0];
                y = y + dy[0];
                if(x < rows && x >=0 && y < cols && y >= 0){
                    cal += 1;
                    ans.push_back({x,y});
                }
                rStart++;
            }
            if(cal >= total){
                break;
            }
            rStart = 0;
            while(rStart < count){
                x = x + dx[1];
                y = y + dy[1];
                if(x < rows && x >=0 && y < cols && y >= 0){
                    cal += 1;
                    ans.push_back({x,y});
                }
                rStart++;
            }
            if(cal >= total){
                break;
            }
            rStart = 0;
            count += 1;
            while(rStart < count){
                x = x + dx[2];
                y = y + dy[2];
                if(x < rows && x >=0 && y < cols && y >= 0){
                    cal += 1;
                    ans.push_back({x,y});
                }
                rStart++;
            }
            if(cal >= total){
                break;
            }
            rStart = 0;
            while(rStart < count){
                x = x + dx[3];
                y = y + dy[3];
                if(x < rows && x >=0 && y < cols && y >= 0){
                    cal += 1;
                    ans.push_back({x,y});
                }
                rStart++;
            }
            if(cal >= total){
                break;
            }
            count += 1;
        }
        return ans;
    }
};