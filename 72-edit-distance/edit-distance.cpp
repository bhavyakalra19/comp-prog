class Solution {
public:
    int n;
    int m;
    int getAns(string word1, string word2, int i, int j, vector<vector<int>> &dp){
        if(i == n){
            return m - j;
        }
        if(j == m){
            return n - i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(word1[i] == word2[j]){
            return dp[i][j] = getAns(word1, word2 , i+1, j+1, dp);
        }
        return dp[i][j] = 1 + min(getAns(word1,word2,i+1,j,dp), min(getAns(word1,word2,i+1,j+1,dp), getAns(word1,word2,i,j+1,dp)));
    }

    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return getAns(word1,word2,0,0,dp);
    }
};