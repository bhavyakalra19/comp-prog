class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> check(n);
        for(int i = 1; i < n; i++){
            if((nums[i] - nums[i-1]) % 2 == 0){
                check[i] = 0;
            }else{
                check[i] = check[i-1] + 1;
            }
        }
        n = queries.size();
        vector<bool> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = ((check[queries[i][1]] - check[queries[i][0]]) == (queries[i][1] - queries[i][0]));
        }
        return ans;
    }
};