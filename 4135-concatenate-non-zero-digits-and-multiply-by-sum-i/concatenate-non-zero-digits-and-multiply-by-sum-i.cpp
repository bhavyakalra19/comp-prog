class Solution {
public:
    long long sumAndMultiply(int n) {
        long long curr = 0;
        long long ten = 1;
        int sum = 0;
        while(n > 0){
            int x = n % 10;
            if(x > 0){
                curr = curr + x * ten;
                sum += x;
                ten *= 10;
            }
            n /= 10;
        }
        return curr * sum;
    }
};