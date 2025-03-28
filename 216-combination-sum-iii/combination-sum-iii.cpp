class Solution {
public:
    void getAns(int a, int k, int target, vector<vector<int>> &ans, vector<int> &check){
        if(target == 0 && k == 0){
            ans.push_back(check);
            return;
        }
        if(a > 9 || k == 0 || a > target) return;
        getAns(a+1, k,target,ans, check);
        check.push_back(a);
        getAns(a + 1, k-1, target - a, ans, check);
        check.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> check;
        getAns(1, k, n, ans, check);
        return ans;
    }
};