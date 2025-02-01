class Solution {
public:
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
        vector<int> dp(n+1,0);
        for(int i = n-1; i >= 0; i--){
            if(s[i] == 'a'){
                dp[i] = dp[i+1];
            }else{
                dp[i] = min(1 + dp[i+1], check[i+1]);
            }
        }
        return dp[0];
    }
};