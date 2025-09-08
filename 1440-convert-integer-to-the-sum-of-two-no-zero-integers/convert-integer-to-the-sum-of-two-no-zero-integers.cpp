class Solution {
public:
    int checkZero(int a){
        while(a > 0){
            if(a % 10 == 0) return false;
            a /= 10; 
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n/2; i++){
            if(checkZero(i) && checkZero(n-i)) return {i, n-i};
        }
        return {1,n-1};
    }
};