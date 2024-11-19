class Solution {
public:
    int n;
    int m;
    bool getAns(string s, string p, int i, int j, vector<vector<int>> &dp){
        if((i == n && j == m) || (i == n && j == m - 1 && p[j] == '*')){
            return true;
        }
        if(i == n || j == m){
            return false;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(p[j] == '*'){
            return dp[i][j] = getAns(s,p,i+1,j,dp) || getAns(s,p,i+1,j+1,dp) || getAns(s,p,i,j+1,dp);
        }else if(p[j] == '?' || s[i] == p[j]){
            return dp[i][j] = getAns(s,p,i+1,j+1,dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        if(n == 0 && m == 0){
            return true;
        }
        if(m == 0){
            return false;
        }
        string check = "";
        check += p[0];
        int j = 0;
        for(int i = 1; i < m; i++){
            if((p[i] == '*') && check[j] == '*'){
                continue;
            }
            check += p[i];
            j++;
        }
        m = check.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,false));
        dp[0][0] = true;
        for(int i = 0; i < m; i++){
            if(check[i] == '*'){
                dp[0][i+1] = true;
            }else{
                break;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(check[j] == '*'){
                    dp[i+1][j+1] = dp[i][j] || dp[i+1][j] || dp[i][j+1];
                }else if(s[i] == check[j] || check[j] == '?'){
                    dp[i+1][j+1] = dp[i][j];
                }
            }
        }
        return dp[n][m];
        // return getAns(s,check,0,0,dp);
    }
};