class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3){
            return *max_element(nums.begin(),nums.end());
        }
        int prev1 = nums[0];
        int prev2 = 0;
        int curr = nums[0];
        for(int i = 1; i < n - 1; i++){
            curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        prev1 = nums[1];
        prev2 = 0;
        int curr1 = nums[1];
        for(int i = 2; i < n; i++){
            curr1 = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr1;
        }
        return max(curr,curr1);
    }
};