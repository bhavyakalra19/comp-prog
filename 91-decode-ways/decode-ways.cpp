class Solution {
public:
    int getAns(string &s, int i, int &n, vector<int> &dp){
        if(i == n){
            return 1;
        }
        if(i > n || s[i] == '0'){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        if((s[i] == '1') || (s[i] == '2' && (i + 1 < n) && ((int)(s[i+1] - '0') < 7))){
            return dp[i] = getAns(s,i+1,n,dp) + getAns(s,i+2,n,dp);
        }
        return dp[i] = getAns(s,i+1,n,dp);
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return getAns(s,0,n,dp);
    }
};