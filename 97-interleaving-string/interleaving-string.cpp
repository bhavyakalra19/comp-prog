class Solution {
public:
    bool getAns(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp){
        if(i + j == s3.size()){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        bool a = false;
        if(i < s1.size() && s1[i] == s3[k]){
            a = getAns(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(j < s2.size() && s2[j] == s3[k]){
            a = a | getAns(s1,s2,s3,i,j+1,k+1,dp);
        }
        return dp[i][j] = a;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 + n2 > s3.size()){
            return false;
        }
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));
        // for(int i = n1 - 1; i >= 0; i--){
        //     for(int j = n2 - 1; j >= 0; j--){
                
        //     }
        // }
        return getAns(s1,s2,s3,0,0,0,dp);
    }
};