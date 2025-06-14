class Solution {
public:
    int n;
    int checkSubstr(string &w1, string &w2, int st, int en){
        vector<int> check(en - st + 1,-1);
        int cnt = 0;
        int ans = 0;
        for(int i = st; i <= en; i++){
            if(w1[i] != w2[i]){
                check[cnt++] = i;
            }
        }
        if(cnt <= 1) return cnt;
        int rem = cnt;
        for(int i = 0; i < rem; i++){
            if(check[i] == -1) continue;
            for(int j = 0; j < rem; j++){
                if(i == j || check[j] == -1) continue;
                if((w1[check[i]] == w2[check[j]]) && w1[check[j]] == w2[check[i]]){
                    check[i] = -1;
                    check[j] = -1;
                    cnt--;
                    break;
                }
            }
        }
        return cnt;
    }
    
    int getAns(string &word1, string &word2, int idx, vector<int> &dp){
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int mn = 1e9;
        for(int i = idx; i < n; i++){
            int a = checkSubstr(word1, word2, idx, i);
            string s1 = word1.substr(idx, i - idx + 1);
            string s2 = word2.substr(idx, i - idx + 1);
            int c = 1e9;
            if(i - idx +1 > 1){
                reverse(s1.begin(), s1.end());
                c = checkSubstr(s1, s2, 0, i - idx + 1); 
            }
            int b = getAns(word1, word2, i + 1, dp);
            if(b >= 1e9) continue;
            mn = min(mn, min(c + 1,a) + b);
        }
        return dp[idx] = mn;
    }

    int minOperations(string word1, string word2) {
        n = word1.size();
        vector<int> dp(n, -1);
        return getAns(word1, word2, 0, dp);
    }
};
