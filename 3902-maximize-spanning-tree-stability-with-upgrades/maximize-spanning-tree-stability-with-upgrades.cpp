class Solution {
public:
    vector<int> adj;
    int find(int a){
        if(adj[a] == a){
            return a;
        }
        return adj[a] = find(adj[a]);
    }

    bool unionFunc(int a, int b){
        int f1 = find(a);
        int f2 = find(b);
        if(f1 == f2) return false;
        adj[f2] = f1;
        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        adj.resize(n);
        vector<int> check(n, 1);
        for(int i = 0; i < n; i++){
            adj[i] = i;
        }
        int mn = INT_MAX;
        int checkVis = 0;
        vector<pair<int,pair<int,int>>> pq;
        for(auto &e : edges){
            if(e[3] == 0){
                pq.push_back({e[2], {e[0], e[1]}});
            }else{
                if(!unionFunc(e[0], e[1])){
                    return -1;
                }else{
                    mn = min(mn, e[2]);
                    checkVis += check[e[0]];
                    checkVis += check[e[1]];
                    check[e[0]] = 0;
                    check[e[1]] = 0;
                }
            }
        }
        sort(pq.begin(), pq.end());
        int j = pq.size()-1;
        vector<int> ans;
        while(j >= 0){
            pair<int,pair<int,int>> it;
            it = pq[j--];
            int wt = it.first;
            int f = it.second.first;
            int s = it.second.second;
            if(unionFunc(f,s)){
                ans.push_back(wt);
                checkVis += check[f];
                checkVis += check[s];
                check[f] = 0;
                check[s] = 0;
            }
        }
        sort(ans.begin(), ans.end());
        for(auto a : ans){
            if(k > 0){
                mn = min(mn, 2 * a);
                k--;
            }else{
                mn = min(mn, a);
            }
        }
        for(int i = 0; i < n; i++){
            if(find(i) != find(0)) return -1;
        }
        return checkVis == n ? mn : -1;
    }
};