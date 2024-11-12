class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());
        vector<pair<int,int>> check;
        int m = queries.size();
        for(int i = 0; i < m; i++){
            check.push_back({queries[i],i});
        }
        sort(check.begin(),check.end());
        vector<int> ans(m,0);
        int mx = 0;
        // for(int i = 0; i < n; i++){
        //     mx = max(mx,items[i][1]);
        //     items[i][1] = mx;
        // }
        int j = -1;
        for(int i = 0; i < m; i++ ){
            while(j + 1 < n && check[i].first >= items[j+1][0]){
                j++;
                mx = max(mx,items[j][1]);
            }
            if(j != -1){
                ans[check[i].second] = mx;
            }
        }
        return ans;
    }
};