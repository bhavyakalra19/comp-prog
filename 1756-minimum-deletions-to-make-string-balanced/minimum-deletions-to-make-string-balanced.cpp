class Solution {
public:
    int getAns(string &s, int idx, int v, vector<vector<int>> &dp, vector<int> &check){
        if(idx == s.size()){
            return 0;
        }
        if(v == 1){
            return check[idx];
        }
        if(dp[idx][v] != -1){
            return dp[idx][v];
        }

        if(v == 0){
           if(s[idx] == 'a'){
                return dp[idx][v] = getAns(s,idx+1,v,dp,check);
           }else{
                return dp[idx][v] = min(getAns(s,idx+1,1,dp,check), 1 + getAns(s,idx+1,v,dp,check));
           }
        }
        return 4;
    }

    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> check(n,0);
        int sm = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'a'){
                sm += 1;
            }
            check[i] = sm;
        }
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return getAns(s,0,0,dp,check);
    }
};