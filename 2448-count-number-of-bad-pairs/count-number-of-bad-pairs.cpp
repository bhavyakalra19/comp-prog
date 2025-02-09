class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += i - mp[nums[i] - i];
            mp[nums[i] - i]++;
        }
        return ans;
    }
};