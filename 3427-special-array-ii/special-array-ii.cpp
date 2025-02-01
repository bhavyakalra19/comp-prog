class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> check(n);
        check[0] = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] % 2 == nums[i-1] % 2){
                check[i] = check[i-1];
            }else{
                check[i] = check[i-1] + 1;
            }
        }
        vector<bool> ans;
        for(auto q : queries){
            if((q[1] - q[0]) == (check[q[1]] - check[q[0]])){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};