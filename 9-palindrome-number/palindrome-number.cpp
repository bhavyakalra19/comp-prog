class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int check = x;
        long long num = 0;
        while(x > 0){
            num *= 10;
            num += (x%10);
            x /= 10;
        }
        
        return num == check;
    }
};