class Solution {
public:
    int getCount(vector<int> nums, int check){
        int ans = 0;
        int cnt = 0;
        for(auto a : nums){
            if(a <= check){
                cnt += 1;
            }else{
                cnt = 0;
            }
            ans += cnt;
        }
        return ans;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return getCount(nums,right) - getCount(nums,left-1);
    }
};