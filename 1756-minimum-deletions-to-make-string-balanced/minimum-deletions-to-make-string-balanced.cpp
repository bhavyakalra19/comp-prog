class Solution {
public:
    int getAns(string &s, int idx, vector<int> &dp, vector<int> &check){
        if(idx == s.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        if(s[idx] == 'a'){
            return dp[idx] = getAns(s,idx+1,dp,check);
        }
        return dp[idx] = min(check[idx+1], 1 + getAns(s,idx+1,dp,check));
    }

    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> check(n+1,0);
        int sm = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'a'){
                sm += 1;
            }
            check[i] = sm;
        }
        vector<int> dp(n,-1);
        return getAns(s,0,dp,check);
    }
};