class Solution {
public:
    int getAns(long a, long b, long n){
        int ans = 0;
        while(a <= n){
            ans += min(n+1,b) - a;
            a *= 10;
            b *= 10;
        }
        return ans;
    }

    int findKthNumber(int n, int k) {
        long num = 1;
        int i = 1;
        while(i < k){
            int check = getAns(num,num+1,n);
            if(k >= check + i){
                num++;
                i += check;
            }else{
                i++;
                num *= 10;
            }
        }
        return num;
    }
};