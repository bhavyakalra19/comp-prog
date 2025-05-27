class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        int seen = 0;
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            inDegree[e[1]]++;
        }
        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        int ans = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int c = colors[it] - 'a';
            seen++;
            dp[it][c]++;
            ans = max(ans, dp[it][c]);
            for(auto a : adj[it]){
                for(int i = 0; i < 26; i++){
                    dp[a][i] = max(dp[a][i], dp[it][i]);
                }
                if(--inDegree[a] == 0){
                    q.push(a);
                }
            }
        }
        return seen == n ? ans : -1;
    }
};