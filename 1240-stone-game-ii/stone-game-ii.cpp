class Solution {
public:
    int n;
    // int getAns(vector<int> &piles, int i, int m, vector<vector<int>> &dp){
    //     if(i + 2 * m >= n){
    //         return piles[i];
    //     }
    //     if(dp[i][m] != -1) return dp[i][m];
    //     int ans = INT_MAX;
    //     for(int j = i; j < i + 2 * m; j++){
    //         int nm = max(m, j - i + 1);
    //         ans = min(ans, getAns(piles, j + 1, nm, dp));
    //     }
    //     return dp[i][m] = piles[i] - ans;
    // }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        for(int i = n-2; i >= 0; i--){
            piles[i] += piles[i+1];
        }

        for(int i = n-1; i >= 0; i--){
            for(int m = max(n-1, 1); m > 0; m--){
                if(i + 2 * m >= n){
                    dp[i][m] = piles[i];
                }else{
                    int ans = INT_MAX;
                    for(int j = i + 2*m - 1; j >= i; j--){
                        int nm = max(m, j - i + 1);
                        ans = min(ans, dp[j+1][nm]);
                    }
                    dp[i][m] = piles[i] - ans;
                }
            }
        }
        return dp[0][1];
        // return getAns(piles, 0, 1, dp);
    }
};

// if alice playing then he want more sum
//  this to be max -> piles[i] + ... + piles[i+k] + getAns()

// if bob

// getAns() to be min

//but instead take max total stone  - getAns()