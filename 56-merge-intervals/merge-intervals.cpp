class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int j = 0;
        for(int i = 1; i < n; i++){
            if(ans[j][1] >= intervals[i][0]){
                ans[j][1] = max(intervals[i][1], ans[j][1]);
            }else{
                ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
    }
};