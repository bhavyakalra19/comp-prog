class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int mx = 0;
        while(i < n - 1){
            mx = max(mx, i + nums[i]);
            if(mx <= i) return false;
            i++;
        }
        return true;
    }
};