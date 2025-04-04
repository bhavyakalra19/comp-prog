class Solution {
public:
    bool isPalindrome(string &s, int st, int en){
        while(st < en){
            if(s[st] != s[en]) return false;
            st++;
            en--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 1e9);
        dp[n] = 0;
        for(int idx = n-1; idx >= 0; idx--){
            int ans = 1e9;
            for(int i = idx; i < n; i++){
                if(isPalindrome(s, idx, i)){
                    ans = min(ans, 1 + dp[i+1]);
                }
            }
            dp[idx] = ans;
        }
        return dp[0] - 1;
    }
};