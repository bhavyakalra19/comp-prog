class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3){
            return *max_element(nums.begin(),nums.end());
        }
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        int p2 = 0;
        int p1 = nums[1];
        for(int i = 2; i < n; i++){
            if(i < n - 1){
                int curr = max(prev1, nums[i] + prev2);
                prev2 = prev1;
                prev1 = curr;
            }
            int curr = max(p1, nums[i] + p2);
            p2 = p1;
            p1 = curr;
        }
        return max(prev1, p1);
    }
};
