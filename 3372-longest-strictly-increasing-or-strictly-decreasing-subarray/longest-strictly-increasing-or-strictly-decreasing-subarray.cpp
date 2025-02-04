class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mnCnt = 1;
        int mx = 1;
        int mxCnt = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i-1]){
                mxCnt = 1;
            }else{
                mxCnt++;
            }
            if(nums[i] >= nums[i-1]){
                mnCnt = 1;
            }else{
                mnCnt++;
            }
            mx = max(mx, max(mnCnt, mxCnt));
        }
        return mx;
    }
};