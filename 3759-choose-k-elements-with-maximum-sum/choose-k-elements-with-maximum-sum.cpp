class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> check;
        vector<long long> ans(n);
        for(int i = 0; i < n; i++) check.push_back({nums1[i], i});
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        sort(check.begin(), check.end(), [](const pair<int,int> &a, const pair<int,int> &b){
            return a.first < b.first;
        });
        int prev = -1;
        for(int i = 0; i < n; i++){
            int a = check[i].second;
            if(check[i].first == prev){
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
            prev = check[i].first;
        }
        return ans;
    }
};