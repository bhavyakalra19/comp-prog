class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto it = pq.top();
            pq.pop();
            pq.push({it.first * multiplier, it.second});
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            nums[it.second] = it.first;
        }
        return nums;
    }
};