class Solution {
public:
    // bool getAns(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
    //     if(i < 0 && j < 0){
    //         return true;
    //     }
    //     if(j < 0){
    //         return false;
    //     }
    //     if(i < 0){
    //         while(j >= 0 && s2[j] == '*'){
    //             j--;
    //         }
    //         if(j < 0) return true;
    //         return false;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     if(s1[i] == s2[j] || s2[j] == '?'){
    //         return dp[i][j] = getAns(s1,s2,i-1,j-1,dp);
    //     }else if(s2[j] == '*'){
    //         return dp[i][j] = getAns(s1,s2,i-1,j,dp) | getAns(s1,s2,i,j-1,dp);
    //     }
    //     return dp[i][j] = false;
    // }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int i = 0; i < m; i++){
            if(p[i] == '*'){
                dp[0][i+1] = true;
            }else{
                break;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(s[i] == p[j] || p[j] == '?'){
                    dp[i+1][j+1] = dp[i][j];
                }else if(p[j] == '*'){
                    dp[i+1][j+1] = dp[i+1][j] | dp[i][j+1];
                }
            }
        }
        // return getAns(s,p,n-1,m-1,dp);
        return dp[n][m];
    }
};