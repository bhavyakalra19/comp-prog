class Solution {
public:
    char findKthBit(int n, int k) {
        int mutation = 0;
        n = 1;
        while(n < k){
            n = (n*2) + 1;
        }
        while(n > 1){
            int check = n/2;
            if(k == check + 1){
                return mutation % 2 == 0 ? '1' : '0';
            }else if(k > check){
                k = n - k + 1;
                mutation++;
            }
            n = check;
        }
        return mutation % 2 == 0 ? '0' : '1';
    }
};