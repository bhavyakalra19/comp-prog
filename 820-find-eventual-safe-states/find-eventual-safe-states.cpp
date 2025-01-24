class Solution {
public:
    bool getAns(vector<vector<int>> &graph, int idx, vector<int> &check, vector<bool> vis){
        if(graph[idx].size() == 0){
            check[idx] = 1;
            return true;
        }
        if(check[idx] != 2){
            return check[idx];
        }
        if(vis[idx] && graph[idx].size() != 0){
            check[idx] = 0;
            return false;
        }
        bool a = true;
        vis[idx] = true;
        for(int i = 0; i < graph[idx].size(); i++){
            a = a & getAns(graph, graph[idx][i], check, vis);
        }
        return check[idx] = a;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> check(n,2);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            vector<bool> vis(n,false);
            if(getAns(graph,i,check,vis)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};