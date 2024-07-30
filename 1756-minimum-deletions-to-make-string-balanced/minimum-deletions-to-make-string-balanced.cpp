class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int b = 0;
        vector<int> f(n+1,0);
        for(int i = 1; i <= n; ++i){
            if(s[i-1] == 'b'){
                ++b;
                f[i] = f[i-1];
            }else{
                f[i] = min(f[i-1] + 1, b);
            }
        }
        return f[n];
    }
};