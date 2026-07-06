class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int cnt = 0;
        int low = intervals[0][0];
        int high = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] == low || intervals[i][1] <= high){
                cnt++;
            }else{
                low = intervals[i][0];
                high = intervals[i][1];
            }
        }
        return n - cnt;
    }
};

// prev = -1
// if prev < interval[i][0]:
// prev = interval[i][1]
// cnt++;
// i++;
// continue;
