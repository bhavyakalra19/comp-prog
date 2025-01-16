class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        n1 %= 2;
        n2 %= 2;
        int ans = 0;
        if(n1){
            for(auto a : nums2){
                ans ^= a;
            }
        }
        if(n2){
            for(auto a : nums1){
                ans ^= a;
            }
        }
        return ans;
    }
};

