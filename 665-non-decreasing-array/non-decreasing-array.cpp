class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cn = 0;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i+1]){
                if(cn == 1){
                    return false;
                }
                if(i != 0 && nums[i-1] > nums[i+1]){
                    nums[i+1] = nums[i];
                }
                cn++;
            }
        }
        return true;
    }
};