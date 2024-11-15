class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = -1;
        int j = 0;
        while(j < n){
            if(nums[j] != 0 && i != -1){
                swap(nums[i],nums[j]);
                i++;
                while(i <= j && nums[i] != 0){
                    i++;
                }
            }
            if(nums[j] == 0 && i == -1){
                i = j;
            }
            j++;
        }
    }
};