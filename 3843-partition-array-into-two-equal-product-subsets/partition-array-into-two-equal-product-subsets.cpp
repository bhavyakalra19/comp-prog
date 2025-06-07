class Solution {
public:
    int n;
    int mx;
    // bool getAns(long long curr, vector<int> &nums, long long &target, long long check){
    //     if(curr == target){
    //         long long rem = 1;
    //         for(int i = 0; i < n; i++){
    //             if(((check >> i) & 1) != 1){
    //                 rem *= nums[i];
    //             }
    //         }
    //         return rem == target;
    //     }
    //     if(check == mx || curr > target) return false;
    //     for(int i = 0; i < n; i++){
    //         if(!((check >> i) & 1)){
    //             if(getAns(curr * nums[i], nums, target, (check | (1 << i)))) return true;
    //         }
    //     }
    //     return false;
    // }

    bool getAns(long long curr, long long rem, long long target, int idx, vector<int> &nums){
        if(curr == rem && rem == target && idx == n) return true;
        if(curr > target || rem > target || idx == n) return false;
        if(getAns(curr * nums[idx], rem, target, idx + 1, nums)) return true;
        if(getAns(curr, rem * nums[idx], target, idx + 1, nums)) return true;
        return false;
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        n = nums.size();
        mx = (1 << n) - 1;
        long long curr = 1;
        long long check = 0;
        return getAns(1, 1, target, 0, nums);
    }
};