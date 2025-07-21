// m * ((m-1) ^ (n-k-1)) * (n-1 C k)

class Solution {
public:
    int MOD = 1e9 + 7;

    long long modInverse(long long a, long long mod){
        long long res = 1;
        long long power = mod - 2;

        while (power){
            if (power & 1)
                res = res * a % mod;
            a = a * a % mod;
            power >>= 1;
        }

        return res;
    }

    int nCr(int n, int r){
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;
        long long res = 1;
        for (int i = 1; i <= r; i++){
            res = res * (n - r + i) % MOD;
            res = res * modInverse(i, MOD) % MOD;
        }
        return (int)res;
    }

    int countGoodArrays(int n, int m, int k) {
        long long ans = 1;
        long long a = m-1;
        int b = n-k-1;
        while(b > 0){
            if(b & 1){
                ans = (ans * a) % MOD;
            }
            b >>= 1;
            a = (a * a) % MOD;
        }
        return (((1LL * m * ans) % MOD) * nCr(n-1, k)) % MOD;
    }
};



