class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // trying with famous algo of replace and get Value
        vector<int> ans;
        ans.push_back(nums[0]);
        int n = nums.size();
        int curr = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] > ans[curr]){
                curr++;
                ans.push_back(nums[i]);
            }else{
                int st = 0;
                int en = curr;
                int best = 0;
                while(st <= en){
                    int mid = (st + en)/2;
                    if(ans[mid] >= nums[i]){
                        best = mid;
                        en = mid - 1;
                    }else{
                        st = mid + 1;
                    }
                }
                ans[best] = nums[i];
            }
        }
        return curr + 1;
    }
};