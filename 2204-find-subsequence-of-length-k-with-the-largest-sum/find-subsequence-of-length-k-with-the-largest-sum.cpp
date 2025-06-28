class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> check;
        for(int i = 0; i < n; i++){
            check.push_back({nums[i], i});
        }
        sort(check.begin(), check.end(), [](const pair<int,int> &a, const pair<int,int> &b){
            return a.first > b.first;
        });
        sort(check.begin(), check.begin() + k, [](const pair<int,int> &a, const pair<int,int> &b){
            return a.second < b.second;
        });
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(check[i].first);
        }
        return ans;
    }
};