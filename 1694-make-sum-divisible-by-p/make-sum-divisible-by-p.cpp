class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sm = 0;
        for(auto &a : nums) sm = (sm + a) % p;
        if(sm == 0) return 0;
        unordered_map<int,int> mp;
        int ch = sm;
        sm = 0;
        mp[0] = -1;
        int ans = n;
        for(int i = 0; i < n; i++){
            sm = (sm + nums[i]) % p;
            int target = (sm + p - ch) % p;
            if(mp.find(target) != mp.end()){
                ans = min(ans, i - mp[target]);
            }
            mp[sm] = i;
        }
        return ans == n ? -1 : ans;
    }
};