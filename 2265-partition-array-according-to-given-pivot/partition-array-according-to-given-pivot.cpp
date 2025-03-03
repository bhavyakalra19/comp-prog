class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int sm = 0;
        int pc = 0;
        for(auto &a : nums){
            if(a < pivot) sm++;
            if(a == pivot) pc++;
        }
        int st = 0;
        int pi = sm;
        int j = sm + pc;
        vector<int> ans(n);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot){
                ans[st++] = nums[i];
            }else if(nums[i] == pivot){
                ans[pi++] = nums[i];
            }else{
                ans[j++] = nums[i];
            }
        }
        return ans;
    }
};