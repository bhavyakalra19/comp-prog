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
        int divs = 0;
        int temp = nums[idx];
        while (temp > 0) {
            int val = temp;
            int mults = 0;
            
            while (val <= sum) {
                ans = min(ans, divs + mults + getAns(nums, idx + 1, sum - val, dp));
                val *= 2;
                mults++;
            }
            
            temp /= 2;
            divs++;
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
