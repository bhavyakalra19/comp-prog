class Solution {
public:

    void getAns(vector<int> &nums, int idx, int &ans, int curr, int &mx){
        if(curr == mx){
            ans++;
        }
        for(int i = idx; i < nums.size(); i++){
            getAns(nums, i + 1, ans, curr | nums[i], mx);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int check = 0;
        for(auto &a : nums){
            check |= a;
        }
        int ans = 0;
        getAns(nums, 0, ans, 0, check);
        return ans;
    }
};