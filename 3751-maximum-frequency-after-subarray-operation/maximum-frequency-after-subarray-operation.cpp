class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int cs = 0;
        for(int i = 0; i < n; i++){
            cs += (nums[i] == k);
        }
        int ans = 0;
        for(int a = 1; a < 51; a++){
            if(a == k){
                continue;
            }
            int sm = 0;
            int mxSum = 0;
            for(int i = 0; i < n; i++){
                sm += (nums[i] == k) ? -1 : nums[i] == a ? 1 : 0;
                sm = max(sm,0);
                mxSum = max(sm,mxSum);
            }
            ans = max(ans,mxSum);
        }
        return cs + ans;
    }
};