class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int cmn = 0;
        int mn = nums[0];
        int cmx = 0;
        int mx = nums[0];
        int total = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            cmn += nums[i];
            if(cmn > 0){
                cmn = 0;
            }
            mn = min(mn,cmn);

            cmx += nums[i];
            mx = max(mx,cmx);
            if(cmx < 0){
                cmx = 0;
            }

            total += nums[i];
        }
        return mx > 0 ? max(mx, total - mn) : mx;
    }
};