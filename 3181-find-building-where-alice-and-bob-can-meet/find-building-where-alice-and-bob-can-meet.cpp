class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int q = queries.size();
        vector<int> result(q,-1);
        vector<vector<pair<int,int>>> check(n);
        for(int i = 0; i < q; i++){
            int a = queries[i][0];
            int b = queries[i][1];
            if(a > b){
                swap(a,b);
            }
            if(a == b || heights[a] < heights[b]){
                result[i] = b;
            }else{
                check[b].push_back({heights[a], i});
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i < n; i++){
            for(auto a : check[i]) pq.push(a);
            while(!pq.empty() && pq.top().first < heights[i]){
                result[pq.top().second] = i;
                pq.pop();
            }
        }
        return result;
    }
};