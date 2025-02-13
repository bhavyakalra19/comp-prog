class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto a : nums){
            pq.push(a);
        }
        int ans = 0;
        while(!pq.empty()){
            auto it1 = pq.top();
            pq.pop();
            if(pq.empty() || it1 >= k) return ans;
            auto it2 = pq.top();
            pq.pop();
            pq.push(((it1 * 2) + it2));
            ans++;
        }
        return ans;
    }
};