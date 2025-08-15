class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n < 4) return false;
        while(n > 1){
            long long a = 4;
            while(a * a < n){
                a *= a;
            }
            if(n % a != 0) return false;
            n /= a;
        }
        return true;
    }
};