class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        vector<long long> dp(n);
        dp.assign(points[0].begin(),points[0].end());

        for(int i = 1; i < m; i++){
            vector<long long> left(n), right(n), newDp(n);
            newDp.assign(points[i].begin(),points[i].end());

            left[0] = dp[0];
            for(int j = 1; j < n; j++){
                left[j] = max(left[j-1] - 1, dp[j]);
            }

            right[n-1] = dp[n-1];
            for(int j = n - 2; j >= 0; j--){
                right[j] = max(right[j+1] - 1, dp[j]);
            }
            for(int j = 0; j < n; j++){
                newDp[j] += max(left[j],right[j]);
            }
            dp = newDp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};