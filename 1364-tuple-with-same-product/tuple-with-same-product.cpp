class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = i+1; j < n; j++){
                mp[nums[i] * nums[j]] += 1;
            }
        }
        for(auto m : mp){
            if(m.second > 1){
                ans += ((m.second - 1) * (m.second)) * 4;
            }
        }
        return ans;
    }
};