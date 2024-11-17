class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,-1});
        long long sum = 0;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            pq.push({sum,i});
            while(pq.top().first <= (sum - k)){
                ans = min(ans, i - pq.top().second);
                pq.pop();
            }
            if(ans == 1){
                return ans;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};