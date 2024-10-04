class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long check = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            check += nums[i];
        }
        check = check % p;
        if(check == 0){
            return 0;
        }
        unordered_map<int,int> mp;
        int ps = 0;
        int mn = n;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            ps = (ps + nums[i])%p;
            int currMod = (ps - check + p) % p;
            if(mp.find(currMod) != mp.end()){
                mn = min(mn, i - mp[currMod]);
            }
            mp[ps] = i;
        }
        return mn == n ? -1 : mn;
    }
};