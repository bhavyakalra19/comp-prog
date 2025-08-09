class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long a = 1;
        if(n <= 0) return false;
        if(n == 1) return true;
        while(a < n){
            a <<= 1;
            if(a == n) return true;
        }
        return false;
    }
};