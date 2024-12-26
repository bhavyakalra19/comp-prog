class Solution {
public:
    // int getAns(vector<int> &nums, int idx, int k, vector<vector<int>> &dp){
    //     if(idx == 0){
    //         if(nums[0] == 0 && k == 0){
    //             return 2;
    //         }
    //         if(k == 0 || nums[0] == k){
    //             return 1;
    //         }
    //     }
    // }

    int findTargetSumWays(vector<int>& nums, int target) {
        //s2 - s = target
        //s2 = totalSum - s1
        //totalSum - s1 - s1 = target
        //totalSum - target = 2s1
        //(totalSum - target)/2 = s1
        int sum = 0;
        for(auto a : nums) sum += a;
        if(sum - target < 0 || (sum - target) % 2 != 0) return 0;
        target = (sum - target)/2;
        vector<int> prev(target+1,0);
        if(nums[0] <= target) prev[nums[0]] = 1;
        prev[0] = 1;
        if(nums[0] == 0) prev[0] = 2;
        for(int i = 1; i < nums.size(); i++){
            for(int j = target; j >= 0; j--){
                prev[j] = prev[j] + ((nums[i] <= j) ? prev[j - nums[i]] : 0);
            }
        }
        return prev[target];
    }
};