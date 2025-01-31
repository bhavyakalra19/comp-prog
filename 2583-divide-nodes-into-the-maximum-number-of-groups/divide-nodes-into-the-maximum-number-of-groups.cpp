class Solution {
public:
    vector<int> pr;

    bool dfs(vector<vector<int>> &graph, int idx, vector<int> &check, int val){
        for(auto a : graph[idx]){
            if(check[a] == val){
                return false;
            }
            if(check[a] == -1){
                check[a] = 1 - val;
                if(!dfs(graph, a, check, check[a])) return false;
            }
        }
        return true;
    }
    
    bool checkBipartite(vector<vector<int>> &graph){
        int n = graph.size();
        vector<int> check(n,-1);
        for(int i = 0; i < n; i++){
            if(check[i] == -1){
                check[i] = 1;
                if(!dfs(graph, i, check, 1)) return false;
            }
        }
        return true;
    }

    int getAns(vector<vector<int>> &graph, int &n, int idx){
        int ans = 0;
        queue<int> q;
        q.push(idx);
        vector<bool> vis(n,false);
        vis[idx] = true;
        while(!q.empty()){
            int size = q.size();
            while(size){
                --size;
                auto it = q.front();
                q.pop();
                for(auto a : graph[it]){
                    if(!vis[a]){
                        vis[a] = true;
                        q.push(a);
                    }
                }  
            }
            ans++;
        }
        return ans;
    }

    int find(int idx){
        if(pr[idx] == idx){
            return idx;
        }
        return pr[idx] = find(pr[idx]);
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; i++){
            pr.push_back(i);
        }
        for(auto e : edges){
            graph[e[0] - 1].push_back(e[1] - 1);
            graph[e[1] - 1].push_back(e[0] - 1);
            int a = find(e[0] - 1);
            int b = find(e[1] - 1);
            pr[a] = b;
        }
        
        if(!checkBipartite(graph)) return -1;
        int mx = 0;
        vector<int> prMax(n,0);
        for(int i = 0; i < n; i++){
            prMax[find(i)] = max(prMax[find(i)], getAns(graph, n, i));
        }
        for(auto a : prMax){
            mx += a;
        }
        return mx;
    }
};