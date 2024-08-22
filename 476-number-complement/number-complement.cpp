class Solution {
public:
    int findComplement(int num) {
       int ans = 0;
       long long p = 1;
       while(num > 0){
            if(num % 2 == 0){
                ans += p;
            }
            p *= 2;
            num /= 2;
       }
       return ans;
    }
};