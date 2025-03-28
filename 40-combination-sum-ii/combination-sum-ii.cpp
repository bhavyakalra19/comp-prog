class Solution {
public:
    void getAns(vector<int> &nums, int idx, int target, vector<vector<int>> &ans, vector<int> &check){
        if(target == 0){
            ans.push_back(check);
            return;
        }
        if(idx == nums.size()) return;
        for(int i = idx; i < nums.size(); i++){
            if(i != idx && nums[i] == nums[i-1]) continue;
            if(target < nums[i]) break;
            check.push_back(nums[i]);
            getAns(nums, i + 1, target - nums[i], ans, check);
            check.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> check;
        getAns(candidates, 0, target, ans, check);
        return ans;
    }
};