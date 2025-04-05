class Solution {
public:
    void getAns(vector<int> &nums, int idx, int a, int &sum){
        if(idx < 0){
            sum += a;
            return;
        }
        getAns(nums, idx - 1, a, sum);
        getAns(nums, idx - 1, a ^ nums[idx], sum);
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        getAns(nums, n-1, 0, sum);
        return sum;
    }
};