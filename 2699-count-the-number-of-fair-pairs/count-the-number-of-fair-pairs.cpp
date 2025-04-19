class Solution {
public:
    long long getAns(vector<int> &nums, int target){
        int i = 0;
        int n = nums.size();
        int r = n - 1;
        long long ans = 0;
        while(i < r){
            if(nums[i] + nums[r] > target){
                r--;
            }else{
                ans += r - i;
                i++;
            }
        }
        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return getAns(nums, upper) - getAns(nums, lower - 1);
    }
};