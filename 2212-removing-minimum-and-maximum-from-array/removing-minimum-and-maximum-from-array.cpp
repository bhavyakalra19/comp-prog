class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX;
        int mx = INT_MIN;
        int mnIdx = -1;
        int mxIdx = -1;

        for(int i = 0; i < n; i++){
            if(nums[i] < mn){
                mn = nums[i];
                mnIdx = i;
            }
            if(nums[i] > mx){
                mx = nums[i];
                mxIdx = i;
            }
        }

        int ans = n;
        ans = min(ans, max(mnIdx, mxIdx) + 1);
        ans = min(ans, n - min(mnIdx, mxIdx));
        ans = min(ans, min(mnIdx, mxIdx) + 1 + n - max(mnIdx, mxIdx));
        return ans;
    }
};

