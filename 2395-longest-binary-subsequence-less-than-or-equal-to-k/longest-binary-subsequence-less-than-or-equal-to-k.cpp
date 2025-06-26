class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int windLen = 0;
        int temp = k;
        while(k > 0){
            windLen++;
            k >>= 1;
        }
        k = temp;
        vector<int> check(n, 0);
        int zc = 0;
        for(int i = 0; i < n; i++){
            check[i] = zc;
            if(s[i] == '0'){
                zc++;
            }
        }
        int i = n-windLen;
        int num = 0;
        if(windLen > n){
            return n;
        }
        if(windLen > 0){
            for(int a = n-windLen+1; a < n; a++){
                num <<= 1;
                if(s[a] == '1'){
                    num += 1;
                }
            }
        }
        int ans = 0;
        while(i >= 0){
            if(s[i] == '1'){
                num += (1 << (windLen - 1));
            }
            if(num > k){
                ans = max(ans, check[i] + windLen - 1);
            }else{
                ans = max(ans, check[i] + windLen);
            }
            num = num >> 1;
            i--;
        }
        return ans;
    }
};
