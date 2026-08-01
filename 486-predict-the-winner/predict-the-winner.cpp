class Solution {
public:
    vector<vector<vector<int>>> dp;
    int getAns(int i, int j, int &n, vector<int> &nums, int x){
        if(i == j){
            return nums[i];
        }
        if(dp[i][j][x] != -1) return dp[i][j][x];
        int a = nums[i] - getAns(i+1, j, n, nums, x ^ 1);
        int b = nums[j] - getAns(i, j-1, n, nums, x ^ 1);
        return dp[i][j][x] = max(a, b);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return getAns(0, n-1, n, nums, 0) >= 0;
    }
};