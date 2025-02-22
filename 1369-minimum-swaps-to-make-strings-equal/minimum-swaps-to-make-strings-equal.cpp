class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int a = 0;
        int b = 0;
        int n = s1.size();
        int ux = 0;
        int uy = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] == 'x'){
                a++;
            }else{
                b++;
            }
            if(s2[i] == 'x'){
                a++;
            }else{
                b++;
            }

            if(s1[i] != s2[i]){
                if(s1[i] == 'x'){
                    ux++;
                }else{
                    uy++;
                }
            }
        }
        if(a % 2 != 0 || b % 2 != 0) return -1;
        int ans = 0;
        ans += ux / 2 + uy / 2;
        if(ux % 2 != 0) ans += 2;
        return ans;
    }
};
