class Solution {
public:
    vector<vector<int>> ans;

    void getAns(vector<int> candidates, int idx, int target, vector<int> check){
        if(target == 0){
            ans.push_back(check);
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            if(candidates[i] > target){
                break;
            }
            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }
            check.push_back(candidates[i]);
            getAns(candidates,i+1,target-candidates[i],check);
            check.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> check;
        getAns(candidates,0,target,check);
        return ans;
    }
};