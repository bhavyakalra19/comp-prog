class Solution {
public:
    vector<vector<int>> dp;
    int getAns(int i, int j, int &n, vector<int> &nums){
        if(i == j){
            return nums[i];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int a = nums[i] - getAns(i+1, j, n, nums);
        int b = nums[j] - getAns(i, j-1, n, nums);
        return dp[i][j] = max(a, b);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++){
            dp[i][i] = nums[i];
        }

        for(int j = 1; j < n; j++){
            for(int i = j-1; i >= 0; i--){
                int pickLeft = nums[i] - dp[i+1][j];
                int pickRight = nums[j] - dp[i][j-1];
                dp[i][j] = max(pickLeft, pickRight);
            }
        }
        return dp[0][n-1] >= 0;

        // return getAns(0, n-1, n, nums) >= 0;
    }
};