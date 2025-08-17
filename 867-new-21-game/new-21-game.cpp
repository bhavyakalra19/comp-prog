class Solution {
public:
    double getCount(int curr, int &maxPts, vector<double> &dp, int &n, int &k){
        if(curr >= k){
            if(curr <= n) return 1;
            return 0;
        }
        if(dp[curr] != -1) return dp[curr];
        double a = 0;
        for(int i = 1; i <= maxPts; i++){
            a += getCount(curr + i, maxPts, dp, n, k) / maxPts;
        }
        return dp[curr] = a;
    }

    double new21Game(int n, int k, int maxPts) {
        if(k + maxPts <= n) return 1;
        vector<double> dp(k + maxPts + 1, 0.0);
        double sum = 0;
        for(int i = k; i <= n; i++){
            dp[i] = 1.0;
            sum += dp[i] / maxPts;
        }
        for(int curr = k - 1; curr >= 0; curr--){
            dp[curr] = sum;
            sum += dp[curr] / maxPts;
            sum -= dp[curr + maxPts] / maxPts;
        }
        // double nCount = getCount(0, maxPts, ndp, n, k);
        return dp[0];
    }
};