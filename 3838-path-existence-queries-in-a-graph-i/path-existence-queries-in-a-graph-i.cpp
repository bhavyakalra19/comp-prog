class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int curr = 1;
        vector<int> check(n);
        check[0] = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i-1] > maxDiff){
                curr++;
            }
            check[i] = curr;
        }
        vector<bool> ans;
        for(auto &a : queries){
            if(check[a[0]] != check[a[1]]){
                ans.push_back(false);
            }else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};