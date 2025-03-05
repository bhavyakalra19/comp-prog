class Solution {
public:
    long long coloredCells(int n) {
        n =  n*2 - 1;
        long long sum = n;
        n -= 2;
        while(n > 0){
            sum += 2 * n;
            n -= 2;
        }
        return sum;
    }
};