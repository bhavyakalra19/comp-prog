class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        map<double, int> horizontal_area, vertical_area;
        for (auto& rect : rectangles) {
            double sx = rect[0];
            double sy = rect[1];
            double ex = rect[2];
            double ey = rect[3];
            vertical_area[sx + 0.1] += 1;
            vertical_area[ex] -= 1;
            horizontal_area[sy + 0.1] += 1;
            horizontal_area[ey] -= 1;
        }

        auto helper = [&](map<double, int>& areas) {
            vector<pair<double, int>> sorted_areas;
            for(auto const& [key, val] : areas){
                sorted_areas.emplace_back(key, val);
            }
            
            sort(sorted_areas.begin(), sorted_areas.end());
            int area_acc = 0, prev_area_acc = 0, cnt = 0;
            for (auto& [k, v] : sorted_areas) {
                area_acc += v;
                if (area_acc == 0) {
                    cnt++;
                }
            }
            return cnt > 2;
        };

        return helper(horizontal_area) || helper(vertical_area);
    }
};