class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> graphs(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
        pq.push({0, 0, 1});
        if(n == 1) return 0;
        for(auto &a : edges){
            graphs[a[0]].push_back({a[1], a[2]});
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int w = it[0];
            int node = it[1];
            int curr = it[2];
    
            if(dist[node][curr] < w) continue;

            for(auto &a : graphs[node]){
                int new_node = a.first;
                int new_weight = a.second;
                int new_curr = curr;
                if(labels[node] == labels[new_node]){
                    new_curr++;
                }else{
                    new_curr = 1;
                }
                if(new_curr > k) continue;
                if(dist[new_node][new_curr] > w + new_weight){
                    if(new_node != n-1) pq.push({w + new_weight, new_node, new_curr});
                    dist[new_node][new_curr] = w + new_weight;
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i <= k; i++){
            if(dist[n-1][i] > 0) ans = min(ans, dist[n-1][i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};


// 0 -> 1 (1) a
// 1 -> 2 (1) a
// 0 -> 2 (3) b


// if label[i] == label[j]: 
//     curr++;
// else:
//     curr = 1

// less a, less w


// [{w1, c1}, {w2, c2}]
// if trail has less w:
//     then move curr trail to 0th index

//     if stored trail at 0th index has less consecutive or same consecutive with lesser weight


// 4 , 10

// 10, 6


// 12, 4