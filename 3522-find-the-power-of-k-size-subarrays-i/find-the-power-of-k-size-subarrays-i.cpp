class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int i = 0;
        for(int j = 0; j < n; j++){
            if(j > 0 && nums[j] != nums[j-1] + 1){
                i = j;
            }
            if(j >= k - 1){
                if(j - i + 1 >= k){
                    ans.push_back(nums[j]);
                }else{
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};