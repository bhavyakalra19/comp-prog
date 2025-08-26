class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0;
        int check = 0;
        for(auto &d : dimensions){
            int sum = ((d[0] * d[0]) + (d[1] * d[1]));
            if(sum > check){
                check = sum;
                area = d[0] * d[1];
            }else if(sum == check){
                area = max(area, d[0] * d[1]);
            }
        }
        return area;
    }
};