class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
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