class Solution {
public:
    int getAns(vector<int> graph[], int num, vector<bool> &vis, vector<vector<int>> &sub){
        if(vis[num] == true){
            return 0;
        }
        if(graph[num].size() == 0){
            return 1;
        }
        int b = 0;        
        vis[num] = true;
        for(int i = 0; i < graph[num].size(); i++){
            if(vis[graph[num][i]] == false){
                int c = getAns(graph,graph[num][i],vis,sub);
                b += c;
                sub[num].push_back(c);
            }
        }
        return b + 1;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = 0;
        for (auto edge : edges)
            n = max({n, edge[0], edge[1]});
        n++;
        vector<int> graph[n];
        vector<vector<int>> sub(n);
        vector<bool> vis(n,false);
        for(int i = 0; i < n - 1; i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        getAns(graph,0,vis,sub);
        int goodNodesCount = 0;
        for (int i = 0; i < n; i++) {
            bool isGood = true;
            for (int j = 1; j < sub[i].size(); j++) {
                if (sub[i][j] != sub[i][0]) {
                    isGood = false;
                    break;
                }
            }
            if (isGood) {
                goodNodesCount++;
            }
        }
        return goodNodesCount;
    }
};