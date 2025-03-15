class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size();
        unordered_map<int,vector<int>> check;
        unordered_map<int,vector<int>> gp;
        unordered_map<int, bool> bus;
        unordered_map<int, bool> node;
        node[source] = true;
        for(int i = 0; i < n; i++){
            if(routes[i].size() == 1) continue;
            for(auto &a : routes[i]){
                check[i].push_back(a);
                gp[a].push_back(i);
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
                for(auto a : gp[it]){
                    if(bus.find(a) == bus.end()){
                        bus[a] = true;
                        for(auto &e : check[a]){
                            if(node.find(e) == node.end()){
                                q.push(e);
                                node[e] = true;
                                if(e == target){
                                    return ans + 1;
                                }
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