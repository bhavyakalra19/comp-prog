class Solution {
public:
    int getAns(int i, int j, int &n, vector<int> &piles, vector<vector<int>> &dp){
        // if(i == j){
        //     return piles[i];
        // }
        // if(dp[j][j] != -1) return dp[i][j];
        // int a = piles[i] - getAns(i+1, j, n, piles, dp);
        // int b = piles[j] - getAns(i, j-1, n, piles, dp);
        return dp[i][j];
    }

    bool stoneGame(vector<int>& piles) {
        // int n = piles.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return getAns(0, n-1, n, piles, dp) > 0;

        // 1. there are even piles and alice can force bob to choose even or odd index only
        // so in the game alice can choose index even/odd which has higher sum 
        // so alice always wins

        return true;
    }
};
