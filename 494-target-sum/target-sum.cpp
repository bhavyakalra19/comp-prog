class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //s2 - s = target
        //s2 = totalSum - s1
        //totalSum - s1 - s1 = target
        //totalSum - target = 2s1
        //(totalSum - target)/2 = s1
        int n = nums.size();
        int sum = 0;
        for(auto a : nums) sum += a;
        if(sum - target < 0 || (sum - target) % 2 != 0){
            return 0;
        }
        target = (sum - target)/2;
        vector<int> prev(target+1,0);
        if(nums[0] <= target) prev[nums[0]] = 1;
        prev[0] = 1;
        if(nums[0] == 0) prev[0] = 2;
        for(int i = 1; i < n; i++){
            for(int j = target; j >= 0; j--){
                int nt = prev[j];
                int tk = 0;
                if(nums[i] <= j) tk = prev[j - nums[i]];
                prev[j] = nt + tk;
            }
        }
        return prev[target];
    }
};