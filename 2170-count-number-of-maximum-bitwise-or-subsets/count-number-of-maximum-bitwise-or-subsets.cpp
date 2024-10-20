class Solution {
public:
    int ans;
    int n;
    void getAns(int check, vector<int> nums, int idx, int curr){
        if(curr == check){
            ans += 1;
        }

        for(int i = idx; i < n; i++){
            getAns(check,nums,i+1,curr | nums[i]);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int check = 0;
        n = nums.size();
        ans = 0;
        for(auto a : nums){
            check |= a;
        }
        getAns(check, nums, 0, 0);
        return ans;
    }
};