class Solution {
public:
    bool getAns(vector<vector<int>> &graph, int idx, vector<int> &check){
        if(graph[idx].size() == 0){
            return true;
        }
        if(check[idx] != 2){
            return check[idx];
        }
        bool a = true;
        check[idx] = 0;
        for(int i = 0; i < graph[idx].size(); i++){
            a = a & getAns(graph, graph[idx][i], check);
        }
        return check[idx] = a;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> check(n,2);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(getAns(graph,i,check)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};