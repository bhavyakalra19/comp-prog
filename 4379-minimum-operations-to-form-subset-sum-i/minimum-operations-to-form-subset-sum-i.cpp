class Solution {
public:
    int getAns(vector<int> &nums, int idx, int sum, vector<vector<int>> &dp){
        if(sum == 0){
            return 0;
        }
        if(idx == nums.size()){
            return 1e9;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int x = nums[idx];
        int y = x * 2;

        int ans = getAns(nums, idx + 1, sum, dp);
        int cnt = 0;
        while(x > 0){
            if(x <= sum){
                ans = min(ans, cnt + getAns(nums, idx + 1, sum - x, dp));
            }
            x /= 2;
            cnt++;
        }
        cnt = 1;
        while(y <= sum){
            ans = min(ans, cnt + getAns(nums, idx + 1, sum - y, dp));
            y *= 2;
            cnt++;
        }
        return dp[idx][sum] = ans;
    }

    int minOperations(vector<int>& nums, int sum) {
        vector<vector<int>> dp(nums.size(), vector<int> (sum + 1, -1));
        int a = getAns(nums, 0, sum, dp);
        if(a == 1e9) return -1;
        return a;
    }
};

// 5 -> 2 -> 1


