class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mn = INT_MIN;
        int ans = 0;
        int i = 0;
        while(i < n){
            if(mn < (nums[i] - k)){
                mn = max(mn, nums[i] - k);
            }else if (mn >= (nums[i] - k) && mn < (nums[i] + k)){
                mn++;
            }else{
                ans--;
            }
            ans++;
            i++;
        }
        return ans;
    }
};