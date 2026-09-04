class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0;
        int b = 0;
        int c = 0;
        int curr = 1;
        vector<int> nums;
        nums.push_back(1);
        for(int i = 1; i < n; i++){
            int mn = min(nums[a] * 2, min(nums[b] * 3, nums[c] * 5));
            if(nums[a] * 2 == mn){
                a++;
            }
            if(nums[b] * 3 == mn){
                b++;
            }
            if(nums[c] * 5 == mn){
                c++;
            }
            nums.push_back(mn);
        }
        return nums[n-1];
    }
};

// a = 3
// b = 2
// c = 1

// 2
// 3
// 4
