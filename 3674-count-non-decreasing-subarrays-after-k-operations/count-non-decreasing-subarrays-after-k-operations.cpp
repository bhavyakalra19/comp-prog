class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, long long k) {
        reverse(nums.begin(), nums.end());
        int n = nums.size();
        long long res = 0;
        deque<int> dq;
        int j = 0;
        for(int i = 0; i < n; i++){
            while(!dq.empty() && nums[dq.front()] < nums[i]){
                int r = dq.front();
                dq.pop_front();
                int l = dq.empty() ? j - 1 : dq.front();
                k -= 1LL *(nums[i] - nums[r]) * (r - l);
            }
            dq.push_front(i);
            while(k < 0){
                k += nums[dq.back()] - nums[j];
                if(nums[dq.back()] == nums[j]){
                    dq.pop_back();
                }
                j++;
            }
            res += i - j + 1;
        }
        return res;
    }
};