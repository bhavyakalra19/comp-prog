class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, long long k) {
        reverse(nums.begin(),nums.end());
        int n = nums.size();
        deque<int> dq;
        int i = 0;
        long long res = 0;
        for(int j = 0; j < n; j++){
            while(!dq.empty() && nums[dq.front()] < nums[j]){
                int r = dq.front();
                dq.pop_front();
                int l = dq.empty() ? i - 1 : dq.front();
                k -= 1LL * (nums[j] - nums[r]) * (r - l);
            }
            dq.push_front(j);
            while(k < 0){
                k += nums[dq.back()] - nums[i];
                if(nums[dq.back()] == nums[i]){
                    dq.pop_back();
                }
                ++i;
            }
            res += j - i + 1;
        }
        return res;
    }
};
