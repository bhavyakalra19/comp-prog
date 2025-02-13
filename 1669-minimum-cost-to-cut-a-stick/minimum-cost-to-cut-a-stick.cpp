class Solution {
public:
    long long getAns(vector<int> &cuts, int i, int j, vector<vector<long long>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        long long ans = INT_MAX;
        for(int k = i; k <= j; k++){
            ans = min(ans, (1LL * cuts[j+1] - cuts[i-1] + getAns(cuts, i, k-1, dp) + getAns(cuts, k+1,j, dp)));
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<long long>> dp(cuts.size(), vector<long long>(cuts.size(), -1));
        return getAns(cuts,1,cuts.size()-2, dp);
    }
};