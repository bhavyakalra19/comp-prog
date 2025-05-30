class Solution {
public:
    // bool getAns(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp){
    //     if(i+j == s3.size()){
    //         return true;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     bool a = false;
    //     if(i < s1.size() && s1[i] == s3[i+j]){
    //         a = getAns(s1,s2,s3,i+1,j,dp);
    //     }
    //     if(j < s2.size() && s2[j] == s3[i+j]){
    //         a = a | getAns(s1,s2,s3,i,j+1,dp);
    //     }
    //     return dp[i][j] = a;
    // }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1 + n2 != n3){
            return false;
        }
        vector<int> prev(n2 + 1, false);
        for(int i = n1; i >= 0; i--){
            vector<int> curr(n2 + 1, false);
            if(i == n1){
                curr[n2] = true;
            }
            for(int j = n2; j >= 0; j--){
                if(i < n1 && s1[i] == s3[i+j]){
                    curr[j] = curr[j] | prev[j];
                }
                if(j < n2 && s2[j] == s3[i+j]){
                    curr[j] = curr[j] | curr[j+1];
                }
            }
            prev = curr;
        }
        return prev[0];
        // return getAns(s1,s2,s3,0,0,dp);
    }
};