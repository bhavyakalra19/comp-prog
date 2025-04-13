class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(!dq.empty() && dq.front() < nums[i]){
                dq.pop_front();
            }
            dq.push_front(nums[i]);
            if(i >= k-1){
                ans.push_back(dq.back());
                if(nums[i - k + 1] == dq.back()){
                    dq.pop_back();
                }
            }
        }
        return ans;
    }
};