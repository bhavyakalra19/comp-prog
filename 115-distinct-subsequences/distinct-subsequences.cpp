class Solution {
public:
    // int getAns(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
    //     if(j < 0){
    //         return 1;
    //     }
    //     if(i < 0){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int a = getAns(s1,s2,i-1,j,dp);
    //     int b = 0;
    //     if(s1[i] == s2[j]){
    //         b = getAns(s1,s2,i-1,j-1,dp);
    //     }
    //     return dp[i][j] = a + b;
    // }

    int numDistinct(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        vector<long long> prev(m+1,0);
        prev[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = m - 1; j >= 0; j--){
                int a = prev[j+1];
                int b = 0;
                if(s1[i] == s2[j]){
                    b = prev[j];
                }
                prev[j+1] = (long long)a + (long long)b;
            }
        }
        return prev[m];
    }
};