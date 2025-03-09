class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> check;
        vector<long long> ans(n);
        for(int i = 0; i < n; i++) check.push_back({nums1[i], i});
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        sort(check.begin(), check.end());
        for(int i = 0; i < n; i++){
            int a = check[i].second;
            if(i > 0 && check[i].first == check[i-1].first){
                ans[a] = ans[check[i-1].second];
            }else{
                ans[a] = sum;
            }
            if(pq.size() < k){
                pq.push(nums2[a]);
                sum += nums2[a];
            }else if(pq.top() < nums2[a]){
                sum -= pq.top() - nums2[a];
                pq.pop();
                pq.push(nums2[a]);
            }
        }
        return ans;
    }
};