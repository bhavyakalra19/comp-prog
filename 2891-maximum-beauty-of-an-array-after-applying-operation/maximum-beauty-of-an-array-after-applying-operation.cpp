class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int prev = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(prev < i && nums[prev] + 2*k < nums[i]){
                prev++;
            }
            ans = max(ans, i - prev + 1);
        }
        return ans;
    }
};