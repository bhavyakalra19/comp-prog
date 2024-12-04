class Solution {
public:
    int getAns(string &w1, string &w2, int i, int j, int &n, int &m, vector<vector<int>> &dp){
        if(i == n){
            return m - j;
        }
        if(j == m){
            return n - i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(w1[i] == w2[j]){
            return dp[i][j] = getAns(w1,w2,i+1,j+1,n,m,dp);
        }
        return dp[i][j] = 1 + min(getAns(w1,w2,i+1,j+1,n,m,dp), min(getAns(w1,w2,i,j+1,n,m,dp), getAns(w1,w2,i+1,j,n,m,dp)));
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return getAns(word1,word2,0,0,n,m,dp);
    }
};
