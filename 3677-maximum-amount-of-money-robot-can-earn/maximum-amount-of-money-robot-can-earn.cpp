class Solution {
public:
    int getAns(vector<vector<int>> &coins, int i, int j, int nut, vector<vector<vector<int>>> &dp){
        if(i < 0 || j < 0){
            return INT_MIN;
        }
        if(i == 0 && j == 0){
            if(coins[0][0] < 0 && nut > 0){
                return 0;
            }
            return coins[0][0];
        }
        if(dp[i][j][nut] != INT_MIN){
            return dp[i][j][nut];
        }
        int a = INT_MIN;
        if(coins[i][j] < 0 && nut){
            a = max(getAns(coins, i-1, j, nut - 1, dp), getAns(coins, i, j-1, nut - 1, dp));
        }
        int b = coins[i][j] + max(getAns(coins, i-1, j, nut, dp), getAns(coins, i, j-1, nut, dp));
        return dp[i][j][nut] = max(a,b);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3,INT_MIN)));
        return getAns(coins, n-1, m-1, 2, dp);
    }
};