class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int zero = 0;
        int n = nums.size();
        int curr = 0;
        for(auto &a : nums){
            curr ^= a;
            if(a == 0) zero++;
        }
        if(curr == 0){
            if(n == zero){
                return 0;
            }
            return n-1;
        }
        return n;
    }
};
