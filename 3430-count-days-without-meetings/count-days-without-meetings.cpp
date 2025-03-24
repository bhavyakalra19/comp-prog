class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        int ans = meetings[0][0] - 1;
        int mx = 0;
        for(int i = 0; i < n-1; i++){
            mx = max(mx, meetings[i][1]);
            if(mx + 1 < meetings[i+1][0]) ans += meetings[i+1][0] - mx - 1;
        }
        mx = max(mx, meetings[n-1][1]);
        ans += days - mx;
        return ans;
    }
};