class Solution {
public:

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<long long>> dp(c+2, vector<long long>(c+2,0));
        for(int i = c; i >= 1; i--){
            for(int j = 1; j <= c; j++){
                if(i > j){
                    continue;
                }
                long long ans = INT_MAX;
                for(int k = i; k <= j; k++){
                    ans = min(ans, 1LL * cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][c];
    }
};