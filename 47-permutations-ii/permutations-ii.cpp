class Solution {
public:
    void getAns(vector<int> &nums, int i, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int k = i; k < nums.size(); k++){
            if(st.find(nums[k]) != st.end()) continue;
            st.insert(nums[k]);
            swap(nums[i], nums[k]);
            getAns(nums, i + 1, ans);
            swap(nums[i], nums[k]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        getAns(nums, 0, ans);
        return ans;
    }
};