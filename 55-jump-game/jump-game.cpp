class Solution {
public:
    bool canJump(vector<int>& nums) {
        int near = 0;
        int mx = 0;
        int n = nums.size();
        int far = 0;
        for(int i = 0; i < n; i++){
            far = max(far, nums[i] + i);
            if(far >= n-1){
                break;
            }
            if(i == far){
                return false;
            }
        }
        return true;
    }
};