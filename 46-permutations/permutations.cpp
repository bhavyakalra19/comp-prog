class Solution {
public:
    void getAns(vector<int> &nums, int idx, vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            getAns(nums, idx+1, ans);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        getAns(nums, 0, ans);
        return ans;
    }
};