class Solution {
public:
    long checkBasic(long a, long b, long n){
        long ans = 0;
        while(a <= n){
            ans += min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return ans;
    }

    int findKthNumber(int n, int k) {
        int num = 1;
        int i = 1;
        while(i < k){
            int check = checkBasic(num, num+1, n);
           if(check + i > k){
                num *= 10;
                i++;
            }else{
                i += check;
                num++;
            }
        }
        return num;
    }
};
