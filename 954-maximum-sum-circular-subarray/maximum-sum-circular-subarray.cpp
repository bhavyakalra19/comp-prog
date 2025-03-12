class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int cmn = 0;
        int cmx = 0;
        int mx = INT_MIN;
        int mn = INT_MAX;
        int total = 0;
        for(int i = 0; i < n; i++){
            cmn += nums[i];
            mn = min(mn, cmn);
            if(cmn > 0) cmn = 0;

            cmx += nums[i];
            mx = max(mx, cmx);
            if(cmx < 0) cmx = 0;

            total += nums[i];
        }
        if(mx < 0) return mx;
        return max(mx, total - mn);
    }
};