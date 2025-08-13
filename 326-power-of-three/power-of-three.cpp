class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1) return true;
        if(n < 3) return false;
        while(n > 1){
            long long a = 3;
            while(a * a < n){
                a *= a;
            }
            if(n % a != 0) return false;
            n = n / a;
        }
        return true;
    }
};