class Solution {
public:
    int getAns(vector<int> &days, int idx, int mx, vector<int> &costs, vector<vector<int>> &dp){
        if(idx == days.size()){
            return 0;
        }
        if(dp[idx][mx] != -1){
            return dp[idx][mx];
        }
        if(days[idx] <= mx){
            return dp[idx][mx] = getAns(days, idx+1, mx, costs, dp);
        }
        int a = costs[0] + getAns(days, idx+1, days[idx], costs, dp);
        int b = costs[1] + getAns(days, idx+1, days[idx] + 6, costs, dp);
        int c = costs[2] + getAns(days, idx+1, days[idx] + 29, costs, dp);
        return dp[idx][mx] = min(a,min(b,c));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>> dp(n, vector<int>(400,-1));
        return getAns(days, 0, 0, costs, dp);
    }
};