class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> check;
        for(int i = 0; i < n; i++){
            check.push_back({nums[i],i});
        }
        sort(check.begin(),check.end());
        long long ans = 0;
        for(auto p : check){
            if(nums[p.second] != 0){
                nums[p.second] = 0;
                if(p.second + 1 < n){
                    nums[p.second + 1] = 0;
                }
                if(p.second - 1 >= 0){
                    nums[p.second - 1] = 0;
                }
                ans += p.first;
            }
        }
        return ans;
    }
};