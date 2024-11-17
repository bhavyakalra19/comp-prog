class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long, int>> pq;
        pq.push_back({0,-1});
        long long sum = 0;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            while(!pq.empty() && sum <= pq.back().first){
                pq.pop_back();
            }
            pq.push_back({sum,i});
            while(!pq.empty() && (sum - k) >= pq.front().first){
                ans = min(ans, i - pq.front().second);
                pq.pop_front();
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};