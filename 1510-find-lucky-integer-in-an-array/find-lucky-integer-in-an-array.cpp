class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        int ans = -1;
        for(auto m : mp){
            if(m.first == m.second) ans = max(ans, m.first);
        }
        return ans;
    }
};