class Solution {
public:
    int getAns(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        int len = nums[j+1] - nums[i-1];
        for(int k = i; k <= j; k++){
            ans = min(ans, len + getAns(nums, i, k-1, dp) + getAns(nums, k + 1, j, dp));
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1, vector<int>(c+1,-1));
        return getAns(cuts, 1, c, dp);
    }
};