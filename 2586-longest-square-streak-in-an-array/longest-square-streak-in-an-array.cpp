class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> mp;
        sort(nums.begin(),nums.end());
        for(auto n : nums){
            mp[n] = 1;
        }
        int ans = 0;
        for(auto n : nums){
            int count = 0;
            long long curr = n;
            while(mp[curr] == 1){
                mp[curr] = 0;
                curr *= curr;
                count++;
            }
            ans = max(ans,count);
        }
        return ans == 1 ? -1 : ans;
    }
};