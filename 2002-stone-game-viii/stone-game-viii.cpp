class Solution {
public:
    // long long getAns(vector<int> &stones, int i, int &n, vector<long long> &dp){
    //     if(i == n-1){
    //         return stones[n-1];
    //     }
    //     if(dp[i] != LONG_MIN) return dp[i];
    //     // remove for loop here by simply take stones and remove the bob's / alice max or skip choosing stone and pick in future as in any position we are just taking ps[i]
    //     long long ans = max(getAns(stones, i+1, n, dp), stones[i] - getAns(stones, i+1, n, dp));
    //     return dp[i] = ans;
    // }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for(int i = 1; i < n; i++){
            stones[i] += stones[i-1];
        }
        // vector<long long> dp(n, LONG_MIN);
        // int a = getAns(stones, 1, n, dp);
        

        // we only need dp[i+1] so remove array
        int dp = stones[n-1];
        for(int i = n-2; i >= 1; i--){
            dp = max(dp, stones[i] - dp);
        }
        return dp;
    }
};

// 7 1 6 16 21 19 13
