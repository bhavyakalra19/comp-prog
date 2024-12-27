class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(str1[i] == str2[j]){
                    dp[i+1][j+1] = 1 + dp[i][j];
                }else{
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        int i = n;
        int j = m;
        string s = "";
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                s = str1[i-1] + s;
                i--;
                j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                s = str1[i-1] + s;
                i--;
            }else{
                s = str2[j-1] + s;
                j--;
            }
        }
        while(i){
            s = str1[i-1] + s;
            i--;
        }
        while(j){
            s = str2[j-1] + s;
            j--;
        }
        return s;
    }
};