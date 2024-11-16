class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] != (nums[i-1] + 1)){
                j = i;
            }
            if(i >= k - 1){
                if(i - j + 1 >= k){
                    ans.push_back(nums[i]);
                }else{
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};