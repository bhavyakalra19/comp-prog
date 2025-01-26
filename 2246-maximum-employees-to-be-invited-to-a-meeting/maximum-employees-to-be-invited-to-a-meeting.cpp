class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();
        vector<int> chain(n,0);
        vector<bool> vis(n,false);
        vector<int> degree(n,0);
        for(int i = 0; i < n; i++){
            degree[fav[i]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int next = fav[it];
            chain[next] = chain[it] + 1;
            vis[it] = true;
            if(vis[next] == false){
                --degree[next];
                if(degree[next] == 0){
                    q.push(next);
                }
            }
        }
        int maxCycle = 0;
        int totalChains = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int currCycle = 0;
                int curr = i;
                while(!vis[curr]){
                    currCycle++;
                    vis[curr] = true;
                    curr = fav[curr];
                }
                if(currCycle == 2){
                    totalChains += 2 + chain[curr] + chain[fav[curr]];
                }else{
                    maxCycle = max(maxCycle, currCycle);
                }
            }
        }
        return max(totalChains, maxCycle);
    }
};
