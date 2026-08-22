class Solution {
public:
    long long getNum(long long start, long long sm, long long left){
        // 9 + 1
        // if left = 8 -> 8 / sm 
        long long check_digit = start + ((left - 1) / sm) + 1;
        int place = check_digit % 10;
        check_digit /= 10;
        if(check_digit % 2 == 0){
            // b is even increasing order
            check_digit *= 10;
            check_digit += place;
        }else{
            // b is odd decreasing order
            check_digit *= 10;
            check_digit += (9 - place);
        }
        int digit_num = sm - (left % sm == 0 ? sm : left % sm);
    
        while(digit_num > 0){
            check_digit /= 10;
            digit_num--;
        }
        return check_digit % 10;
    }
    
    int kthDigit(long long k) {
        long long sm = 2;
        long long start = 9;
        long long total = 9;
        long long actual_start = 9;
        if(k <= 9) return k;
        while(total + (start * 10 * sm) < k){
            total += start * 10 * sm;
            start *= 10;
            sm += 1;
            actual_start = actual_start * 10 + 9;
        }
        return getNum(actual_start, sm, k - total);
    }
};
// 1 - 9 -> 1 -> 9 * 1
// 10 - 99 -> 2 -> 90 * 2
// 100 - 999 -> 3 -> 900 * 3


// 6 -> 3 + 9 => 12th -> 

// 5 -> digit -> k % sm;