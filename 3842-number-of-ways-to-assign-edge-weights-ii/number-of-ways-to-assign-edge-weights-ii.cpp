class Solution {
public:
    vector<vector<int>> binary_map;
    int height;
    unordered_map<int,vector<int>> nodes;
    unordered_map<int,bool> vis;
    vector<int> depth;
    
    void createBinaryLiftingMap(int curr, int prev, int c){
        binary_map[curr][0] = prev;
        depth[curr] = c;
        for(int i = 1; i <= height; i++){
            binary_map[curr][i] = binary_map[binary_map[curr][i-1]][i-1];
        }
        for(auto &a : nodes[curr]){
            if(!vis[a]){
                vis[a] = true;
                createBinaryLiftingMap(a, curr, c+1);
            }
        }
    }

    int resolveDepth(int curr, int node){
        int h = height;
        while(h >= 0){
            if((1 << h) <= curr){
                node = binary_map[node][h];
                curr -= (1 << h);
            }
            h--;
        }
        return node;
    }

    int getLCA(int a, int b){
        int depth_a = depth[a];
        int depth_b = depth[b];

        if(depth_a > depth_b){
            a = resolveDepth(depth_a - depth_b, a);
        }else if(depth_a < depth_b){
            b = resolveDepth(depth_b - depth_a, b);
        }

        if(a == b) return a;

        for(int i = height; i >= 0; i--){
            if(binary_map[a][i] != binary_map[b][i]){
                a = binary_map[a][i];
                b = binary_map[b][i];
            }
        }
        return binary_map[a][0];
    }

    int mod = 1e9 + 7;
    unordered_map<int,int> dp;
    int getDist(int a){
        if(a <= 1) return a;
        if(dp.find(a) != dp.end()) return dp[a];
        return dp[a] = (2 * getDist(a-1)) % mod;
    }

    int nodesDistance(int a, int b){
        int c = getLCA(a, b);
        int d = depth[a] + depth[b] - 2 * depth[c];
        return getDist(d);
    }


    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        height = 0;
        int n = edges.size() + 1;
        depth.resize(n+2, 0);
        for(auto &a : edges){
            nodes[a[0]].push_back(a[1]);
            nodes[a[1]].push_back(a[0]);
        }
        height = log2(n);
        binary_map.resize(n+1, vector<int>(height+1, 1));
        vis[1] = true;
        createBinaryLiftingMap(1, 1, 0);
        vector<int> ans; 
        for(auto &a : queries){
            ans.push_back(nodesDistance(a[0], a[1]));
        }
        return ans;
    }
};

//Binary Lifting setup for lowest common ancestors to find gap between nodes
//use dynamic programming to get total number of cases where sum is odd i.e.
// 2 ^ n  / 2 = 2 ^(n-1)


//Binary Lifting -> get max Depth from root 
// calculate 2^ log(max depth) 

// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8


// map[curr][0] = curr - 1
// map[curr][1] = map[map[curr][0]][0]
// map[curr][2] = map[map[curr][1]][1]