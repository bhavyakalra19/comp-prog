class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int k = (1 << maximumBit) - 1;
        int t = 0;
        vector<int> ans;
        for(auto a : nums){
            t = t ^ a;
        }
        for(int i = 0; i < n; i++){
            ans.push_back(t^k);
            t = t ^ nums[n-i-1];
        }
        return ans;
    }
};