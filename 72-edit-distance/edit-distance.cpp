class Solution {
public:
    int getAns(string word1, string word2, int i, int j, vector<vector<int>> &dp){
        if(i < 0){
            return j+1;
        }
        if(j < 0){
            return i+1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(word1[i] == word2[j]){
            return dp[i][j] = getAns(word1, word2 , i-1, j-1, dp);
        }
        return dp[i][j] = 1 + min(getAns(word1,word2,i-1,j,dp), min(getAns(word1,word2,i-1,j-1,dp), getAns(word1,word2,i,j-1,dp)));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 1; i <= m; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i <= n; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(word1[i] == word2[j]){
                    dp[i+1][j+1] = dp[i][j];
                }else{
                    dp[i+1][j+1] = 1 + min(dp[i+1][j], min(dp[i][j+1], dp[i][j]));
                }
            }
        }
        return dp[n][m];
        // return getAns(word1,word2,n-1,m-1,dp);
    }
};