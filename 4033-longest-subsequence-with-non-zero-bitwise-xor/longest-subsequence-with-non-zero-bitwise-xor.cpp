class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int zero = 0;
        int curr = 0;
        for(auto &a : nums){
            curr ^= a;
            if(a == 0) zero++;
        }
        if(curr == 0){
            if(nums.size() == zero){
                return 0;
            }
            return nums.size() - 1;
        }
        return nums.size();
    }
};
