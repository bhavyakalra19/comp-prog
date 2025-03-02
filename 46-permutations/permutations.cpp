class Solution {
public:
    void getAns(vector<int> &nums, vector<vector<int>> &ans, int idx, int n){
        if(idx == n){
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i < n; i++){
            swap(nums[idx], nums[i]);
            getAns(nums, ans, idx + 1, n);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getAns(nums, ans, 0, nums.size());
        return ans;
    }
};