class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> mp;
        map<int,int> below;
        for(auto &it : nums){
            mp[it]++;
            below[max(0,it - k)] += 1;
            below[it] = below[it];
            below[it + k + 1] -= 1;
        }
        int ans = 0;
        int sm = 0;
        for(auto &m : below){
            int a = m.first;
            sm += below[a];
            ans = max(ans, mp[a] + min(sm - mp[a], numOperations));
        }
        return ans;
    }
};