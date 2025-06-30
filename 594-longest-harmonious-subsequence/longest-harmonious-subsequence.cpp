class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        for(auto m : mp){
            if(mp.find(m.first + 1) != mp.end()){
                ans = max(ans, m.second + mp[m.first + 1]);
            }
        }
        return ans;
    }
};