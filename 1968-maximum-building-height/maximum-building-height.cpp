class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        // int curr_mx = n;
        // int curr = 0;
        // int mx = 0;
        // vector<int> ans(n, 0);
        // unordered_map<int, int> check;
        // for(auto &a : res){
        //     check[a[0] - 1] = a[1];
        // }
        // for(int i = n-1; i > 0; i--){
        //     if(check.find(i) != check.end() && check[i] <= curr_mx){
        //         curr_mx = check[i];
        //     }else{
        //         curr_mx = min(curr_mx + 1, n);
        //     }
        //     ans[i] = curr_mx;
        // }
        // for(int i = 1; i < n; i++){
        //     curr = min(curr+1, ans[i]);
        //     mx = max(mx, curr);
        // }
        // return mx;

        // n is too large instead of this update the restrictions from left to right and then right to left.
        res.push_back({1, 0});
        res.push_back({n, n});
        sort(res.begin(), res.end());
        int curr = 0;
        int m = res.size();
        for(int i = 1; i < m; i++){
            int dist = res[i][0] - res[i-1][0];
            res[i][1] = min(res[i][1], res[i-1][1] + dist);
        }
        for(int i = m-2; i >= 0; i--){
            int dist = res[i+1][0] - res[i][0];
            res[i][1] = min(res[i][1], res[i+1][1] + dist);
        }
        for(int i = 1; i < m; i++){
            vector<int> a = res[i];
            vector<int> b = res[i-1];
            int dist = a[0] - b[0];
            curr = max(curr, (dist + a[1] + b[1])/2);
        }
        return curr;
    }
};


// 1 x  x  3