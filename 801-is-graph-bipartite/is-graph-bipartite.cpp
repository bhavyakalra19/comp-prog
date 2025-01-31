class Solution {
public:
    bool dfs(vector<vector<int>> &graph, int idx, vector<int> &check, int val){
        for(auto a : graph[idx]){
            if(check[a] == val){
                return false;
            }
            if(check[a] == -1){
                check[a] = 1 - val;
                if(!dfs(graph,a,check,check[a])) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> check(n,-1);
        for(int i = 0; i < n; i++){
            if(check[i] == -1){
                check[i] = 1;
                if(!dfs(graph, i, check, 1)){
                    return false;
                }
            }
        }
        return true;
    }
};