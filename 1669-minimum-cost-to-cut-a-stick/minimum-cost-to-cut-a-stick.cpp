class Solution {
public:
    int getAns(vector<int> &cuts, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k <= j; k++){
            ans = min(ans, cuts[j+1] - cuts[i-1] + getAns(cuts, i, k-1, dp) + getAns(cuts, k+1, j, dp));
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        int a = cuts.size();
        vector<vector<int>> dp(a, vector<int>(a,-1));
        return getAns(cuts, 1, a - 2, dp);
    }
};