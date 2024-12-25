class Solution {
public:
    // int getAns(vector<int> nums, int idx, int k, vector<vector<int>> &dp){
    //     if(idx == 0){
    //         if(nums[idx] == 0 && k == 0){
    //             return 2;
    //         }
    //         if(k == 0 || k == nums[0]){
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     if(dp[idx][k] != -1){
    //         return dp[idx][k];
    //     }
    //     int nt = getAns(nums, idx - 1, k, dp);
    //     int tk = 0;
    //     if(nums[idx] <= k) tk = getAns(nums, idx - 1, k - nums[idx], dp);
    //     return dp[idx][k] = nt + tk;
    // }

    int findTargetSumWays(vector<int>& nums, int target) {
        //s2 - s1 = target;
        //total - s1 - s1 = target;
        //(total - target)/2 = s1;
        int sum = 0;
        int n = nums.size();
        for(auto a : nums) sum += a;
        if(sum - target < 0 || (sum - target)%2 != 0){
            return 0;
        }
        target = (sum - target)/2;
        vector<int> prev(target+1,0);
        prev[0] = 1;
        if(nums[0] <= target){
            prev[nums[0]] = 1;
        }
        if(nums[0] == 0) prev[0] = 2;
        for(int i = 1; i < n; i++){
            for(int j = target; j >= 0; j--){
                int nt = prev[j];
                int tk =  0;
                if(j >= nums[i]) tk = prev[j - nums[i]];
                prev[j] = nt + tk;
            }
        }
        return prev[target];
        // return getAns(nums,n-1,target,dp);
    }

};