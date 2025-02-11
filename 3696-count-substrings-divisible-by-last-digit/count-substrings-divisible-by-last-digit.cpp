class Solution {
public:
    long long dp[100005][10][2];
    long long getAns(string &s, int idx, int st, int &ld, int rem){
        if(idx == s.size()) return 0;
        if(dp[idx][rem][st] != -1) return dp[idx][rem][st];
        long long ans = 0;
        int digit = s[idx] - '0';
        if(!st){
            ans += getAns(s, idx + 1, 0,ld, 0);
            int nr = digit % ld;
            if(nr == 0 && ld == digit) ans++;
            ans += getAns(s, idx + 1, 1, ld, nr);
        }else{
            int nr = ((rem * 10) + digit) % ld;
            if(nr == 0 && ld == digit) ans++;
            ans += getAns(s, idx + 1, 1, ld, nr);
        }
        return dp[idx][rem][st] = ans;
    }

    long long countSubstrings(string s) {
        int n = s.size();
        long long ans = 0;
        for(int d = 1; d <= 9; d++){
            for(int i = 0 ; i <= n ; i++) {
                for(int j = 0 ; j < d ; j++) {
                    for(int k = 0 ; k < 2 ; k++) {
                        dp[i][j][k] = -1;
                    }
                }
            }
            ans += getAns(s, 0, 0, d, 0);
        }
        return ans;
    }
};



