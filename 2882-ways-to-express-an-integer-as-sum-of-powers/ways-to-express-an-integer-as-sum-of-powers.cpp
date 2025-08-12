class Solution {
public:
    int mod = 1e9 + 7;
    int getAns(int idx, vector<int> &check, int k, vector<vector<int>> &dp){
        if(k == 0) return 1;
        if(idx == check.size()) return 0;
        if(check[idx] > k) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];
        int a = getAns(idx + 1, check, k, dp);
        a = (a + getAns(idx + 1, check, k - check[idx], dp)) % mod;
        return dp[idx][k] = a;
    }

    int numberOfWays(int n, int x) {
        if(n == 1) return 1;
        int mx = 1;
        vector<int> check;
        while(1){
            int a = 1;
            for(int i = 0; i < x; i++){
                a *= mx;
            }
            if(a > n){
                break;
            }
            check.push_back(a);
            mx++;
        }
        int sz = check.size();
        vector<vector<int>> dp(sz, vector<int>(n + 1, -1));
        return getAns(0, check, n, dp);
    }
};