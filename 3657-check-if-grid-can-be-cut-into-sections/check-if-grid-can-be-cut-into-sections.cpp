class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        map<double, int> xline;
        map<double, int> yline;
        for(auto r : rectangles){
            xline[r[0]] -= 1;
            xline[r[2] - 0.1] += 1;
            yline[r[1]] -= 1;
            yline[r[3] - 0.1] += 1;
        }
        int sum = 0;
        int cnt = 0;
        for(auto m : xline){
            sum += m.second;
            if(sum == 0){
                cnt++;
                if(cnt > 2) return true;
            }
        }
        sum = 0;
        cnt = 0;
        for(auto m : yline){
            sum += m.second;
            if(sum == 0){
                cnt++;
                if(cnt > 2) return true;
            }
        }
        return false;
    }
};