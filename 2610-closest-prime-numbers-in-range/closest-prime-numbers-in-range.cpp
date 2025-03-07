class Solution {
public:
    bool isPrime(int n){
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        int prev = -1;
        int ans = INT_MAX;
        vector<int> check = {-1,-1};
        for(int i = max(2,left); i <= right; i++){
            if(isPrime(i)){
                if(prev != -1 && (i - prev) < ans){
                    ans = i - prev;
                    check = {prev, i};
                }
                prev = i;
            }
        }
        return check;
    }
};