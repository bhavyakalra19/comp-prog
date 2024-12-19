class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> check;
        unordered_map<int, vector<int>> gp;
        unordered_map<int,bool> visitBus;
        unordered_map<int,bool> visitNode;
        for(int i = 0; i < n; i++){
            int m = routes[i].size();
            if(m == 1){
                continue;
            }
            for(int j = 0; j < m; j++){
                check[routes[i][j]].push_back(i);
                gp[i].push_back(routes[i][j]);
            }
        }
        queue<int> q;
        int ans = 0;
        q.push(source);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                for(auto bus : check[it]){
                    if(visitBus[bus]){
                        continue;
                    }
                    visitBus[bus] = true;
                    for(auto node : gp[bus]){
                        if(!visitNode[node]){
                            q.push(node);
                            visitNode[node] = true;
                            if(node == target){
                                return ans + 1;
                            }
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};