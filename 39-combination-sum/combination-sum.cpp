class Solution {
public:
    int n;
    void getAns(vector<int> &candidates, int idx, int target, vector<vector<int>> &ans, vector<int> &check){
        if(target == 0){
            ans.push_back(check);
            return;
        }
        if(idx == candidates.size()) return;
        for(int i = idx; i < n; i++){
            if(candidates[i] > target) break;
            check.push_back(candidates[i]);
            getAns(candidates, i, target - candidates[i], ans, check);
            check.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        vector<int> check;
        vector<vector<int>> ans;
        getAns(candidates, 0, target, ans, check);
        return ans;
    }
};