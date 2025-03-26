class Solution {
public:
    int getAns(vector<int> &nums, int idx, vector<int> &dp){
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = nums[idx] + getAns(nums, idx - 2, dp);
        int notTake = getAns(nums, idx - 1, dp);
        return dp[idx] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1,0);
        int p1 = 0;
        int p2 = 0;
        for(int i = 0; i < n; i++){
            int take = nums[i] + p2;
            int notTake = p1;
            int curr = max(take, notTake);
            p2 = p1;
            p1 = curr;
        }
        return p1;
    }
};