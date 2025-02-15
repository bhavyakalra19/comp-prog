class Solution {
public:
    double getAns(vector<vector<int>> &s, double y, int &cnt){
        double up = 0;
        double lw = 0;
        for(int i = 0; i < s.size(); i++){
            double side = s[i][2];
            if(side == 0) continue;
            if(s[i][1] >= y){
                up += side * side;
            }else if((double)(s[i][1] + s[i][2]) <= y){
                lw += side * side;
            }else{
                cnt++;
                double su1 = (double)(s[i][1] + s[i][2]) - y;
                double sl1 = y - (double)s[i][1];
                up += side * su1;
                lw += side * sl1;
            }
        }
        return up - lw;
    }

    double separateSquares(vector<vector<int>>& squares) {
        int mx = 0;
        int mn = INT_MAX;
        for(auto s : squares){
            mn = min(mn, s[1]);
            mx = max(mx, s[1] + s[2]);
        }
        double st = mn;
        double en = mx;
        double ms = INT_MAX;
        double ans;
        if(st == en) return st;
        while(st < en){
            double mid = (st + en) / (double) 2;
            int cnt = 0;
            double a = getAns(squares,mid,cnt);
            if(abs(a) <= ms){
                ms = abs(a);
                ans = mid;
            }
            if(a == 0 && cnt == 0){
                ans = -1;
                for(auto s : squares){
                    double y = s[1] + s[2];
                    if(y <= mid){
                        ans = max(ans, y);
                    }
                }
                break;
            }
            if(a > 0){
                st = mid + 0.00001;
            }else{
                en = mid - 0.00001;
            }
        }
        return ans;
    }
};