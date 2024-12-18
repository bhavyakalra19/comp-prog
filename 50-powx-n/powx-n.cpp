class Solution {
public:
    double getAns(double x, long n){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 1.0 / getAns(x,-n);
        }
        if(n % 2 == 1){
            return x * getAns(x*x,n/2);
        }
        return getAns(x*x,n/2);
    }

    double myPow(double x, int n) {
        return getAns(x,n);
    }
};