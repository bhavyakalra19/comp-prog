class Solution {
public:
    unordered_map<int,int> weight;
    unordered_map<int,int> level;

    void dfs(vector<vector<pair<int,int>>> &adj, int curr, int par, int l, int w, int &log, vector<vector<int>> &memo){
        weight[curr] = w;
        level[curr] = l;
        memo[curr][0] = par;
        for(int i = 1; i < log; i++){
            memo[curr][i] = memo[memo[curr][i-1]][i-1];
        }
        for(auto &a : adj[curr]){
            if(a.first != par){
                dfs(adj, a.first, curr, l + 1, w + a.second, log, memo);
            }
        }
    }

    int lca(vector<vector<int>> &memo, int a1, int a2, int log){
        if(level[a1] > level[a2]){
            swap(a1, a2);
        }
        int w1 = weight[a1];
        int w2 = weight[a2];
        int diff = level[a2] - level[a1];
        for(int i = 0; i < log; i++){
            if(diff & (1 << i)){
                a2 = memo[a2][i];
            }
        }
        if(a1 == a2) return w1 + w2 - (2 * weight[a1]);
        for(int i = log-1; i >= 0; i--){
            if(memo[a1][i] != memo[a2][i]){
                a1 = memo[a1][i];
                a2 = memo[a2][i];
            }
        }
        int par = memo[a1][0];
        return w1 + w2 - (2 * weight[par]);
    }

    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &a : edges){
            adj[a[0]].push_back({a[1], a[2]});
            adj[a[1]].push_back({a[0], a[2]});
        }
        int sum = 1;
        int log = n;
        while(log > 0){
            sum += 1;
            log >>= 1;
        }
        vector<vector<int>> memo(n, vector<int>(sum + 1));
        dfs(adj, 0, 0, 0, 0, sum, memo);
        vector<int> ans;
        for(auto &q : queries){
            int a = lca(memo, q[0], q[1], sum);
            int b = lca(memo, q[0], q[2], sum);
            int c = lca(memo, q[1], q[2], sum);
            ans.push_back((a + b + c)/2);
        }
        return ans;
    }
};