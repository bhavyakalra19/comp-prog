class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(queries.begin(), queries.end());
        priority_queue<int> pq;
        int j = 0;
        int q = queries.size();
        int sum = 0;
        vector<int> check(n+1, 0);
        for(int i = 0; i < n; i++){
            while(j < q && queries[j][0] == i){
                pq.push(queries[j++][1]);
            }
            while(sum < nums[i]){
                if(pq.empty() || pq.top() < i){
                    return -1;
                }else{
                    sum++;
                    int top = pq.top();
                    check[top]++;
                    pq.pop();
                }
            }
            sum -= check[i];
        }
        return pq.size();
    }
};