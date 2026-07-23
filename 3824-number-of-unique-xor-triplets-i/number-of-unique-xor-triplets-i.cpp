class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int x = 1;
        while(x <= n){
            x = x << 1;
        }
        // before 2 we can't get 0 and 
        //after that take the number which has most highest bit set
        // set all the bit of that number as we can get that number via xor of numbers before that
        // suppose you have 4 -> 100 -> you can maximum get 111 which is 7 via -> 4 ^ 2 ^ 1 
        // so take the number with highes left bit set and set all bit from right to left most bit 
        // or get a number greater than that and -1 
        // but we have to add zero as well so remove the -1 
        // and thats the final answer greater than the bit we can find
        return x;
    }
};

// a ^ b ^ c

// 1 2 3 4 5 6 
//  1-

// n ^ n 

// 1 2 3 

// 1 
// 0 1
// 1 1

// -> 1 , 0 1, 1 1, 0 0
// -> 4  0 0 1

// 1 1 1

// 0 0 0 1 