class Solution {
public:
    void getAns(vector<int> &nums, unordered_map<int,int> &mp, vector<vector<int>> &ans, int idx){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(auto &a : mp){
            if(a.second > 0){
                nums[idx] = a.first;
                mp[a.first] -= 1;
                getAns(nums, mp, ans, idx + 1);
                mp[a.first] += 1;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &a : nums){
            mp[a] += 1;
        }
        vector<vector<int>> ans;
        getAns(nums, mp, ans, 0);
        return ans;
    }
};