class Solution {
public:
    int getCount(int i, vector<vector<int>> &adj, vector<bool> &vis){
        int a = 1;
        vis[i] = true;
        for(auto &b : adj[i]){
            if(!vis[b]){
                a += getCount(b, adj, vis);
            }
        }
        return a;
    }

    long long maxScore(int n, vector<vector<int>>& edges) {
        int mn = n;
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        for(auto &a : edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
            inDegree[a[1]]++;
            inDegree[a[0]]++;
        }
        vector<bool> vis(n, false);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 1 && !vis[i]){
                int cnt = getCount(i, adj, vis);
                vector<long long> check(cnt, 0);
                int k = 0;
                int j = cnt-1;
                int curr = mn - cnt + 1;
                mn -= cnt;
                while(k <= j){
                    check[k] = curr;
                    curr++;
                    k++;
                    if(k <= j){
                        check[j] = curr;
                        j--;
                        curr++;
                    }
                }
                for(int j = 0; j < cnt-1; j++){
                    ans += check[j] * check[j+1];
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int cnt = getCount(i, adj, vis);
                vector<long long> check(cnt, 0);
                int k = 0;
                int j = cnt-1;
                int curr = mn - cnt + 1;
                mn -= cnt;
                while(k <= j){
                    check[k] = curr;
                    curr++;
                    k++;
                    if(k <= j){
                        check[j] = curr;
                        j--;
                        curr++;
                    }
                }
                ans += check[0] * check[cnt-1]; 
                for(int j = 0; j < cnt-1; j++){
                    ans += check[j] * check[j+1];
                }
            }
        }
        return ans;
    }
};