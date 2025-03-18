class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sm = 0;
        int ans = 1;
        while(i < n){
            while((sm & nums[i]) != 0){
                sm ^= nums[j];
                j++;
            }
            sm |= nums[i];
            ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};