class Solution {
public:
    int countValidPrefixes(string s) {
        int zero = 0;
        int one = 0;
        int ans = 0;
        for(auto &a : s){
            if(a == '0'){
                zero++;
            }else{
                one++;
            }
            if(abs(zero - one) <= 1) ans++;
        }
        return ans;
    }
};