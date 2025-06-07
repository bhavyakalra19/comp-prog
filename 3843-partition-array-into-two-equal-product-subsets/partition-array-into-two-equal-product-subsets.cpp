class Solution {
public:
    int n;

    bool getAns(long long curr, long long rem, long long target, int idx, vector<int> &nums){
        if(curr == rem && rem == target && idx == n) return true;
        if(curr > target || rem > target || idx == n) return false;
        if(getAns(curr * nums[idx], rem, target, idx + 1, nums)) return true;
        if(getAns(curr, rem * nums[idx], target, idx + 1, nums)) return true;
        return false;
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        n = nums.size();
        return getAns(1, 1, target, 0, nums);
    }
};