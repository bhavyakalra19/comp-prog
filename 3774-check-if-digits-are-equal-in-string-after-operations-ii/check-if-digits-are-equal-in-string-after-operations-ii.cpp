class Solution {
public:
    int binsmall(int n, int k) {
        if (k > n)
            return 0;
        int fact[5] = {1, 1, 2, 1, 4};
        int numerator = fact[n];
        int denominator = (fact[k] * fact[n - k]) % 5;
        int deninv = 0;
        for (int i = 0; i < 5; i++) {
            if ((denominator * i) % 5 == 1) {
                deninv = i;
                break;
            }
        }
        return (numerator * deninv) % 5;
    }

    int binmod5(int n, int k) {
        int res = 1;
        while (n > 0 || k > 0) {
            int nd = n % 5;
            int kd = k % 5;
            if (kd > nd)
                return 0;
            res = (res * binsmall(nd, kd)) % 5;
            n /= 5;
            k /= 5;
        }
        return res;
    }
    int binmod2(int n, int k) {
        while (k > 0) {
            if ((k & 1) > (n & 1))
                return 0;
            n >>= 1;
            k >>= 1;
        }
        return 1;
    }
    bool hasSameDigits(string s) {
        int n = s.size();
        long long a = 0;
        long long b = 0;
        for(int i = 0; i < n-1; i++){
            int m2 = binmod2(n-2, i);
            int m5 = binmod5(n-2, i);
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