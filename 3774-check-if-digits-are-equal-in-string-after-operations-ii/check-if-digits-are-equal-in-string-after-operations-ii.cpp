class Solution {
public:
    int nCrModpDP(int n, int r, int p) { 
        // The array C is going to store last row of 
        // pascal triangle at the end. And last entry 
        // of last row is nCr 
        int C[r+1]; 
        memset(C, 0, sizeof(C)); 
    
        C[0] = 1; // Top row of Pascal Triangle 
    
        // One by constructs remaining rows of Pascal 
        // Triangle from top to bottom 
        for (int i = 1; i <= n; i++) 
        { 
            // Fill entries of current row using previous 
            // row values 
            for (int j = min(i, r); j > 0; j--) 
    
                // nCj = (n-1)Cj + (n-1)C(j-1); 
                C[j] = (C[j] + C[j-1])%p; 
        } 
        return C[r]; 
    } 
    
    int nCrModpLucas(int n, int r, int p) { 
    // Base case 
    if (r==0) 
        return 1; 
    // Compute last digits of n and r in base p 
    int ni = n%p, ri = r%p; 
    
    // Compute result for last digits computed above, and 
    // for remaining digits.  Multiply the two results and 
    // compute the result of multiplication in modulo p. 
    return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r 
            nCrModpDP(ni, ri, p)) % p;  // Remaining digits 
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