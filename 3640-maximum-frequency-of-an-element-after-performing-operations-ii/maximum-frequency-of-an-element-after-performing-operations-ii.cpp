class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> mp;
        map<int,int> below;
        vector<int> points;
        for(auto &it : nums){
            mp[it]++;
            below[it - k] += 1;
            below[it] = below[it];
            below[it + k + 1] -= 1;
            // points.push_back(it - k);
            // points.push_back(it + k + 1);
            // points.push_back(it);
        }
        // sort(points.begin(), points.end());
        int ans = 1;
        int sm = 0;
        for(auto &m : below){
            int a = m.first;
            sm += below[a];
            ans = max(ans, mp[a] + min(sm - mp[a], numOperations));
        }
        return ans;
    }
};