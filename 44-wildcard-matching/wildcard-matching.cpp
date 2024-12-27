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
        vector<int> prev(m+1,false);
        prev[0] = true;
        int i = 0;
        while(i < m && p[i] == '*'){
            prev[i+1] = true;
            i++;
        }
        for(int i = 0; i < n; i++){
            vector<int> curr(m+1,false);
            for(int j = 0; j < m; j++){
                if(s[i] == p[j] || p[j] == '?'){
                    curr[j+1] = prev[j];
                }else if(p[j] == '*'){
                    curr[j+1] = curr[j] | prev[j+1];
                }
            }
            prev = curr;
        }
        // return getAns(s,p,n-1,m-1,dp);
        return prev[m];
    }
};