class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> check;
        for(int i = 0; i < n; i += 3){
            vector<int> curr;
            for(int j = i; j <= i+2; j++){
                if(nums[j] - nums[i] > k){
                    return {};
                }
                curr.push_back(nums[j]);
            }
            check.push_back(curr);
        }
        return check;
    }
};