class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double st = INT_MAX;
        double en = 0;
        for(auto s : squares){
            st = min(st,(double) s[1]);
            en = max(en, (double)s[1] + s[2]);
        }
        double eps = 1e-5;
        while(en - st > eps){
            double y = (st + en)/2;
            double up = 0;
            double lw = 0;
            for(auto &s : squares){
                double side = s[2];
                double s1 = s[1];
                if(s1 >= y){
                    up += side * side;
                }else if(s1 + side <= y){
                    lw += side * side;
                }else{
                    up += side * ((s1 + side) - y);
                    lw += side * (y - s1);
                }
            }
            up > lw ? st = y : en = y;
        }
        return st;
    }
};