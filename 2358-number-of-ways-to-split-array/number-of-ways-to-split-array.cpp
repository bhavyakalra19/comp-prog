class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        long long fs = 0;
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            fs += nums[i];
            sum -= nums[i];
            if(fs >= sum) ans += 1;
        }
        return ans;
    }
};