class Solution {
public:
    bool getAns(vector<vector<int>> &graph, int i, int val, vector<int> &check){
        check[i] = val;
        for(auto a : graph[i]){
            if(check[a] == val) return false;
            if(check[a] == -1 && !getAns(graph, a, 1 - val, check)) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> check(n,-1);
        for(int i = 0; i < n; i++){
            if(check[i] == -1){
                if(!getAns(graph, i, 0, check)) return false;
            }
        }
        return true;
    }
};