class Solution {
public:
    unordered_map<int,bool> mp;

    int getAns(int i, int &a, int &b, int &x, vector<vector<int>> &dp, int val){
        if(i == x){
            return 0;
        }
        if(i < 0 || i > 6000 || mp.find(i) != mp.end()){
            return 1e9;
        }
        if(dp[i][val] != -1){
            return dp[i][val];
        }
        dp[i][val] = 1 + getAns(i + a, a, b, x, dp, 0);
        if(val == 0){
            dp[i][val] = min(dp[i][val], 1 + getAns(i - b, a, b, x, dp, 1));
        }
        return dp[i][val];
    }

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int mx = 7000;
        for(auto c : forbidden){
            mp[c] = true;
        }
        vector<vector<int>> dp(mx+1, vector<int>(2,-1));
        int ans = getAns(0, a, b, x, dp, 0);
        return ans >= 1e9 ? -1 : ans;
    }
};
