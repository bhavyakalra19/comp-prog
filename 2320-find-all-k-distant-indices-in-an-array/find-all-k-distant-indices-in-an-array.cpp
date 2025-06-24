class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        queue<int> q;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == key){
                q.push(i);
            }
        }
        vector<int> ans;
        if(q.empty()) return ans;
        int prev = -1;
        int next = q.front();
        for(int i = 0; i < n; i++){
            if(q.front() == i){
                prev = i;
                q.pop();
            }
            if(prev != -1 && i - prev <= k){
                ans.push_back(i);
            }else if(!q.empty() && q.front() - i <= k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};