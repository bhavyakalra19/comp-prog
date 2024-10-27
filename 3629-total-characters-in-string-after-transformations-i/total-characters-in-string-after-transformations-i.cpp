class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int mod = 1e9 + 7;
        vector<int> count(26,0);
        for(auto a : s){
            count[a - 'a']++;
        }
        while(t > 0){
            vector<int> tmp(26,0);
            for(int i = 0; i < 26; i++){
                if(i == 25){
                    tmp[0] = (tmp[0] + count[i])%mod;
                    tmp[1] = (tmp[1] + count[i])%mod;
                }else{
                    tmp[i+1] = (tmp[i+1] + count[i])%mod;
                }
            }
            count = tmp;
            t--;
        }
        long long ans = 0;
        for(auto a : count){
            ans = (ans + a)%mod;
        }
        return ans % mod;
    }
};
