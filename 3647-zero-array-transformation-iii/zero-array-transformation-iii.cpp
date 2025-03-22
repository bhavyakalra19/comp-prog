class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        sort(queries.begin(), queries.end());
        priority_queue<int> pq;
        int j = 0;
        int sm = 0;
        int ans = 0;
        vector<int> check(n+1, 0);
        for(int i = 0; i < n; i++){
            sm -= check[i];
            while(j < q && queries[j][0] == i){
                pq.push(queries[j][1]);
                j++;
            }
            while(sm < nums[i]){
                if(pq.empty() || pq.top() < i) return -1;
                int top = pq.top();
                pq.pop();
                sm++;
                ans++;
                check[top + 1]++;
            }
        }
        return pq.size();
    }
};