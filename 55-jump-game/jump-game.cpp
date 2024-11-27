class Solution {
public:
    bool canJump(vector<int>& nums) {
        int near = 0;
        int mx = 0;
        int n = nums.size();
        int far = 0;
        if(n == 1){
            return true;
        }
        for(int i = 0; i < n; i++){
            far = max(far, nums[i] + i);
            if(i == far){
                return false;
            }
            if(far >= n-1){
                break;
            }
        }
        return true;
    }
};