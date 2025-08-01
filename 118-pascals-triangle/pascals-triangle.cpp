class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = 1;
        vector<vector<int>> ans;
        while(n <= numRows){
            vector<int> nums(n, 1);
            if(n > 2){
                for(int i = 1; i < n-1; i++){
                    nums[i] = ans[n-2][i-1] + ans[n-2][i];
                }
            }
            ans.push_back(nums);
            n++;
        }
        return ans;
    }
};