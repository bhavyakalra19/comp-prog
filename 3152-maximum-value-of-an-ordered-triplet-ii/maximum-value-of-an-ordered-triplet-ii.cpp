class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        int mx = 0;
        int rmx = 0;
        for(int i = 0; i < n; i++){
            right[n-1-i] = rmx;
            rmx = max(rmx, nums[n-1-i]);
            mx = max(mx, nums[i]);
            left[i] = mx;
        }
        long long ans = 0;
        for(int i = 1; i < n-1; i++){
            ans = max(ans, (1LL * left[i] - nums[i]) * right[i] * 1LL);
        }
        return ans;
    }
};