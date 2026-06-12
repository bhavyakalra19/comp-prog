class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<int, long long> mp;
    int mx_depth;
    unordered_map<int, bool> vis;

    long long fact(int n){
        if(mp.find(n) != mp.end()){
            return mp[n];
        }
        return mp[n] = (1LL * n * fact(n-1)) % mod;
    }

    void getAns(unordered_map<int,vector<int>> &edge_map, int curr, int depth){
        mx_depth = max(mx_depth, depth);
        for(auto &a : edge_map[curr]){
            if(!vis[a]){
                vis[a] = true;
                getAns(edge_map, a, depth + 1);
            }
        }
    }

    int getResult(int num){
        int ans = 1;
        for(int i = 0; i < num-1; i++){
            ans = (ans * 2) % mod;
        }
        return ans;
    }


    int assignEdgeWeights(vector<vector<int>>& edges) {
        mp[1] = 1;
        mp[0] = 1;
        int n = edges.size();
        unordered_map<int, vector<int>> edge_map;
        for(auto &a : edges){
            edge_map[a[0]].push_back(a[1]);
            edge_map[a[1]].push_back(a[0]);
        }

        mx_depth = 0;
        vis[1] = true;
        getAns(edge_map, 1, 0);
        if(mx_depth == 0) return 0;
        cout << mx_depth << endl;
        return getResult(mx_depth);
    }
};

