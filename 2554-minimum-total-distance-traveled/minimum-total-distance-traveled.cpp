class Solution {
public:
    // long long getAns(vector<int> robot, int i, vector<long long> fact, int j, vector<vector<long long>> &dp){
    //     if(i == m){
    //         return 0;
    //     }
    //     if(j == n){
    //         return LONG_MAX / 10;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     long long b = (long long) abs(robot[i] - fact[j]) + getAns(robot,i+1,fact,j+1,dp);
    //     long long a = getAns(robot,i,fact,j+1,dp);
    //     return dp[i][j] = min(a,b);
    // }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<long long> fact;
        for(auto it : factory){
            long long pos = it[0];
            int limit = it[1];
            for(int i = 0; i < limit; i++){
                fact.push_back(pos);
            }
        }
        int m = robot.size();
        int n = fact.size();
        vector<vector<long long>> dp(m + 1,vector<long long>(n + 1, LONG_MAX / 10));
        for(int i = 0; i <= n; i++){
            dp[0][i] = 0;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                long long take = abs(robot[i-1] - fact[j-1]) + dp[i-1][j-1];
                long long nTake = dp[i][j-1];
                dp[i][j] = min(take, nTake);
            }
        }
        return dp[m][n];
    }
};