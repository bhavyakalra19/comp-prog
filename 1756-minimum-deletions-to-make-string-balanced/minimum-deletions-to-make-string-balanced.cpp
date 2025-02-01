class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int sm = 0;
        vector<int> dp(n+1,0);
        for(int i = n-1; i >= 0; i--){
            if(s[i] == 'a'){
                sm++;
                dp[i] = dp[i+1];
            }else{
                dp[i] = min(sm, 1 + dp[i+1]);
            }
        }
        return dp[0];
    }
};