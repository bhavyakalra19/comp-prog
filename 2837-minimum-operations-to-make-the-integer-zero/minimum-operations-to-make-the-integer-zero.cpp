class Solution {
public:
    int countSetBits(long long x){
        int cnt = 0;
        while(x > 0){
            if(x & 1) cnt++;
            x >>= 1;
        }
        return cnt;
    }

    int makeTheIntegerZero(int num1, int num2) {
        for(int i = 1; i < 61; i++){
            long long x = 1LL * num1 - 1LL * i * num2;
            if(x < i) continue;
            if(countSetBits(x) <= i) return i;
        }
        return -1;
    }
};