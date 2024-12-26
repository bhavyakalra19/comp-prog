class Solution {
public:
    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(s[i] == s2[j]){
                    dp[i+1][j+1] =  1 + dp[i][j];
                }else{
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return n - dp[n][n];
    }
};