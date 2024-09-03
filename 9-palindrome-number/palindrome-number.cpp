class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> check;
        if(x < 0){
            return false;
        }
        while(x > 0){
            check.push_back(x%10);
            x /= 10;
        }
        int n = check.size();
        for(int i = 0; i < n/2; i++){
            if(check[i] != check[n-i-1]){
                return false;
            }
        }
        return true;
    }
};