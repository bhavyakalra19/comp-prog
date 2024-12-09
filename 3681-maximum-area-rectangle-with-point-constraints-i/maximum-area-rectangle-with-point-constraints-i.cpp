class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int check[101][101] = {0};
        for(auto p : points){
            check[p[0]][p[1]] = 1;
        }
        int n = points.size();
        int ans = -1;
        for(int i = 0; i < n; i++){
            int bx = points[i][0];
            int by = points[i][1];
            for(int j = i+1; j < n; j++){
                int ux = points[j][0];
                int uy = points[j][1];
                string a1 = to_string(bx) + '-' + to_string(by);
                string a2 = to_string(ux) + '-' + to_string(uy);
                string a3 = to_string(ux) + '-' + to_string(by);
                string a4 = to_string(bx) + '-' + to_string(uy);
                if(a1 != a2 && a2 != a3 && a3 != a4 && a1 != a4 && a2 != a4 && a1 != a3 && check[bx][uy] == 1 && check[ux][by] == 1){
                    
                    int lx = min(bx,ux);
                    int mx = max(bx,ux);
                    int ly = min(uy,by);
                    int my = max(uy,by);
                    int count = 0;
                    for(int idy = ly; idy <= my; idy++){
                        for(int idx = lx; idx <= mx; idx++){
                            count += check[idx][idy];
                        }
                    }
                    if(count == 4){
                        cout << bx << " " << by << endl;
                        cout << ux << " " << uy << endl;
                        cout << "------" << endl;
                        ans = max(ans, (mx - lx) * (my - ly));
                    }
                }
            }
        }
        return ans;
    }
};
