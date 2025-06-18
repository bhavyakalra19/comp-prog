class Solution {
  public: 
  vector<int> level;
  vector<vector<int>> parent;
  vector<long long> dist;
  int lvl;
  void dfs(int curr, int par, int l, long long d, vector<vector<pair<int,int>>> & adj) {
    dist[curr] = d;
    level[curr] = l;
    parent[curr][0] = par;
    for (int i = 1; i <= lvl; i++) {
      parent[curr][i] = parent[parent[curr][i - 1]][i - 1];
    }
    for (auto & a: adj[curr]) {
      if (a.first != par) {
        dfs(a.first, curr, l + 1, d + 1LL * a.second, adj);
      }
    }
  }
    int getRootNode(int a, int b) {
        if (level[a] < level[b]) {
            swap(a, b);
        }
        int diff = level[a] - level[b];
        for (int i = 0; i <= lvl; i++) {
            if (diff & (1 << i)) {
                a = parent[a][i];
            }
        }
        if (a == b) {
            return a;
        }
        for (int i = lvl; i >= 0; i--) {
            if (parent[a][i] != parent[b][i]) {
                a = parent[a][i];
                b = parent[b][i];
            }
        }
        return parent[a][0];
    }

    int getNodeDist(int a, int d){
        for(int i = lvl; i >= 0; i--){
            if(d & (1 << i)){
                a = parent[a][i];
            }
        }
        return a;
    }

    int getMedianNode(int a, int root, long long d, bool up) {
        int hg = level[a];
        int low = level[root];
        int ans = hg;
        while (low <= hg) {
            int mid = (hg + low) / 2;
            int midNode = getNodeDist(a, level[a] - mid);
            long long distMid = dist[midNode] - dist[root];
            if(distMid == d){
                return midNode;
            }else if(distMid > d){
                ans = midNode;
                hg = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        if(up){
            return parent[ans][0];
        }
        return ans;
    }
    vector<int>findMedian(int n, vector<vector<int>> & edges, vector<vector<int>> & queries) {
        lvl = 0;
        int m = n;
        while(m > 0) {
            lvl++;
            m >>= 1;
        }
        dist.resize(n);
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e: edges) {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        level.resize(n);
        parent.resize(n, vector<int>(lvl + 1));
        dfs(0, 0, 0, 0, adj);
        vector<int>ans;
        for(int i = 0; i<queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            int root = getRootNode(a, b);
            long long aRoot = dist[a] - dist[root];
            long long bRoot = dist[b] - dist[root];
            long long total = (aRoot + bRoot + 1)/ 2;
            cout << root << endl;
            if(aRoot == bRoot) {
                ans.push_back(root);
            }else if(aRoot > bRoot) {
                ans.push_back(getMedianNode(a, root, aRoot - total, true));
            }else{
                ans.push_back(getMedianNode(b, root, total - aRoot, false));
            }
        }
    return ans;
  }
};


//         0
//     1
// 2