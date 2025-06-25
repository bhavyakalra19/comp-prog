class Solution {
public:
    long long mx;
    int ans;
    void dfs(vector<vector<int>> &adj, int curr, int par, vector<int> &cost, long long currCost){
        mx = max(mx, currCost + cost[curr]);
        for(auto &a : adj[curr]){
            if(a != par){
                dfs(adj, a, curr, cost, currCost + cost[curr]);
            }
        }
    }

    long long getAns(vector<vector<int>> &adj, int curr, int par, vector<int> &cost, long long currCost, vector<long long> &check){
        long long mn = LONG_MAX;
        for(auto &a : adj[curr]){
            if(a != par){
                mn = min(mn, getAns(adj, a, curr, cost, currCost + cost[a], check));
            }
        }
        if(mn == LONG_MAX) return check[curr] = mx - currCost;
        return check[curr] = mn;
    }
    
    void sumAns(vector<vector<int>> &adj, int curr, int par, vector<long long> &check, long long currCheck){
        if(check[curr] - currCheck != 0){
            ans += 1;
        }
        for(auto &a : adj[curr]){
            if(a != par){
                sumAns(adj, a, curr, check, check[curr]);
            }
        }
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        mx = 0;
        ans = 0;
        vector<vector<int>> adj(n);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<long long> check(n, INT_MAX);
        dfs(adj, 0, 0, cost, 0);
        getAns(adj, 0, 0, cost, cost[0], check);
        sumAns(adj, 0, 0, check, 0);
        return ans;
    }
};