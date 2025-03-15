class Solution {
public:
    int find(vector<int> &check, int a){
        if(a == check[a]){
            return a;
        }
        return check[a] = find(check, check[a]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> check;
        for(int i = 0; i <= n+1; i++) check.push_back(i);

        for(int i = 0; i < n; i++){
            int a = find(check,edges[i][0]);
            int b = find(check,edges[i][1]);
            if(a == b) return edges[i];
            check[a] = b;
        }
        return {-1,-1};
    }
};