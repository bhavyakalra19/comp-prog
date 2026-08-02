class Solution {
public:
    int n;
    int getAns(int i, vector<int>& stoneValue, vector<int> &dp){
        if(i == n){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int ans = INT_MIN;
        ans = max(ans, stoneValue[i] - getAns(i+1, stoneValue, dp));
        if(i + 1 < n){
            ans = max(ans, stoneValue[i] + stoneValue[i+1] - getAns(i+2, stoneValue, dp));
        }
        if(i + 2 < n){
            ans = max(ans, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - getAns(i+3, stoneValue, dp));
        }
        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<int> dp(n, -1);
        int ans = getAns(0, stoneValue, dp);
        if(ans > 0){
            return "Alice";
        }else if(ans == 0){
            return "Tie";
        }
        return "Bob";
    }
};