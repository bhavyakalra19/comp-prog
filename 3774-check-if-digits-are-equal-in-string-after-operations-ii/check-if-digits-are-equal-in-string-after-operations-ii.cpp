class Solution {
public:
    int nCrModpDP(int n, int r, int p) { 
        int C[r+1]; 
        memset(C, 0, sizeof(C)); 
        C[0] = 1; // Top row of Pascal Triangle 
        for (int i = 1; i <= n; i++) { 
            for (int j = min(i, r); j > 0; j--) 
                C[j] = (C[j] + C[j-1])%p; 
            } 
            return C[r]; 
        }
        int nCrModpLucas(int n, int r, int p) { 
        if (r==0) return 1; 
        int ni = n%p, ri = r%p; 
        return (nCrModpLucas(n/p, r/p, p) * nCrModpDP(ni, ri, p)) % p;
    } 

    bool hasSameDigits(string s) {
        int n = s.size();
        long long a = 0;
        long long b = 0;
        for(int i = 0; i < n-1; i++){
            int m2 = nCrModpLucas(n-2, i, 2);
            int m5 = nCrModpLucas(n-2, i, 5);
            int result;
            for(int i = 0; i < 10; i++){
                if(i % 2 == m2 && i % 5 == m5){
                    result = i;
                    break;
                }
            }
            a = (a + result * (s[i] - '0')) % 10;
            b = (b + result * (s[i+1] - '0')) % 10;
        }
        return a == b;
    }
};