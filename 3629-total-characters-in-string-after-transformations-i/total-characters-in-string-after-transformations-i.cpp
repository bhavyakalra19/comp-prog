class Solution {
public:
    int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> check(26,0);
        int n = s.size();
        for(int i = 0; i < n; i++){
            check[s[i] - 'a']++;
        }
        for(int i = 0; i < t/26; i++){
            vector<int> curr(26,0);
            for(int j = 0; j < 26; j++){
                if(j == 25){
                    curr[j] = (curr[j] + check[j]) % mod;
                    curr[0] = (curr[0] + check[j]) % mod;
                    curr[1] = (curr[1] + check[j]) % mod;
                }else{
                    curr[j] = (curr[j] + check[j]) % mod;
                    curr[j+1] = (curr[j+1] + check[j]) % mod;
                }
            }
            check = curr;
        }
        t = t % 26;
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(i + t >= 26){
                ans = (ans + check[i]) % mod;
                ans = (ans + check[i]) % mod; 
            }else{
                ans = (ans + check[i]) % mod;
            }
        }
        return ans;
    }
};

