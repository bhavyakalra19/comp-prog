class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            ans = (ans + nums[i]) % p;
        }
        if(ans == 0){
            return 0;
        }
        int ps = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int mn = n;
        for(int i = 0; i < n; i++){
            ps = (ps + nums[i])%p;
            int check = (ps - ans + p) % p;
            if(mp.find(check) != mp.end()){
                mn = min(mn,i-mp[check]);
            }
            mp[ps] = i;
        }
        return mn == n ? -1 : mn;
    }
};