class Solution {
public:
    int getAns(vector<vector<int>> &queries, int &i, int j, int target, vector<vector<int>> &dp){
        if(target == 0) return j;
        if(j == queries.size()) return INT_MAX;
        if(dp[target][j] != -1) return dp[target][j];
        int res = getAns(queries, i, j+1, target, dp);
        if(queries[j][0] <= i && queries[j][1] >= i && queries[j][2] <= target) res = min(res, getAns(queries, i, j+1, target - queries[j][2], dp));
        return dp[target][j] = res;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int ans = -1;
        for(int i = 0; i < n; i++){
            vector<vector<int>> dp(nums[i]+1, vector<int>(queries.size(),-1));
            int a = getAns(queries, i, 0, nums[i], dp);
            if(a == INT_MAX) return -1;
            ans = max(ans, a);
        }
        return ans;
    }
};