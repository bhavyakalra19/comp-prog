class Solution {
public:
    int getAns(vector<int> &nums, int ch){
        int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] <= ch){
                ans += i - j + 1;
            }else{
                j = i + 1;
            }
        }
        return ans;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return getAns(nums,right) - getAns(nums, left - 1);
    }
};