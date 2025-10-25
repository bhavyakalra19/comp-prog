class Solution {
public:
    int calculateSum(int n){
        return (n * (n + 1)) / 2;
    }

    int totalMoney(int n) {
        int sevenSum = calculateSum(7);
        int total = n / 7;
        int start = 1 + total;
        int newSum = calculateSum(total - 1) * 7;
        total = sevenSum * total + newSum;
        for(int i = 0; i < n % 7; i++){
            total += start;
            start++;
        }
        return total;
    }
};
