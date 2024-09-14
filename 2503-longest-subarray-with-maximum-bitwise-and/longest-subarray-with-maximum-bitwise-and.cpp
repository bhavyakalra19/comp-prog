class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int mx = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > mx){
                mx = nums[i];
                l = 1;
                ans = 1;
            }else if(nums[i] == mx){
                l += 1;
                ans = max(ans,l);
            }else{
                l = 0;
            }
        }
        return ans;
    }
};