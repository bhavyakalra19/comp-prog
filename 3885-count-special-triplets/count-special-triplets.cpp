class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> count;
        unordered_map<int,int> pairs;
        int ans = 0;
        int zc = 0;
        int za = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                ans = (ans + pairs[nums[i] / 2]) % mod;
            }
            pairs[nums[i]] = (pairs[nums[i]] + count[nums[i] * 2]) % mod;
            count[nums[i]]++;
        }
        return ans;
    }
};

// 0 0 0 0 0 0 0