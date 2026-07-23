class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int x = 1;
        while(x <= n){
            x = x << 1;
        }
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