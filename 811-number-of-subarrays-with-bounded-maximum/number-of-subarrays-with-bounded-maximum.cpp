class Solution {
public:
    int getAns(vector<int> &nums, int check, int &n){
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i < n){
            if(nums[i] > check){
                j = i + 1;
            }
            ans += i - j + 1;
            i++;
        }
        return ans;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        return getAns(nums, right, n) - getAns(nums, left - 1, n);
    }
};

