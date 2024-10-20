class Solution {
public:
    void getAns(int check, vector<int> nums, int idx, int curr, int &ans){
        if(curr == check){
            ans += 1;
        }

        for(int i = idx; i < nums.size(); i++){
            getAns(check,nums,i+1,curr | nums[i],ans);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int check = 0;
        for(auto a : nums){
            check |= a;
        }
        int ans = 0;
        getAns(check, nums, 0, 0, ans);
        return ans;
    }
};