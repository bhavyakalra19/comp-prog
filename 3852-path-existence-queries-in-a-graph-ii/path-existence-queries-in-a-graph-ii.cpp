class Solution {
public:
    // int getRightMost(vector<pair<int,int>> &nodes, int st, int &n, int &mx){
    //     int en = n - 1;
    //     int ans = st;
    //     int ref = st;
    //     while(st <= en){
    //         int mid = (st + en)/2;
    //         if(abs(nodes[mid].first - nodes[ref].first) > mx){
    //             en = mid - 1;
    //         }else{
    //             ans = mid;
    //             st = mid + 1;
    //         }
    //     }
    //     return nodes[ans].second;
    // }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        //first create a array of pairs of {node <-> nums[node]}
        //sort them
        //create check of nodes where if two nodes exist in same component number
        //if yes do binary search on sorted pairs go as far you can go from current node and count number of points in the way

        vector<pair<int,int>> nodes(n);
        for(int i = 0; i < n; i++){
            nodes[i] = {nums[i], i};
        }
        sort(nodes.begin(), nodes.end());
        int curr = 1;
        vector<int> check(n);
        vector<int> start(n);
        start[nodes[0].second] = 0;
        check[nodes[0].second] = 1;
        for(int i = 1; i < n; i++){
            if(nodes[i].first - nodes[i-1].first > maxDiff){
                curr++;
            }
            check[nodes[i].second] = curr;
            start[nodes[i].second] = i;
        }

        //jump binary lifting instead of binary search -> In one jump how much far you can go and similarly 1,2,4,8,16...
        int LOG = 20;
        int right = 0;
        vector<vector<int>> up(n, vector<int>(LOG+1));
        for(int left = 0; left < n; left++){
            while(right + 1 < n && nodes[right+1].first - nodes[left].first <= maxDiff){
                right++;
            }
            up[left][0] = right;
        }

        for(int i = 1; i < LOG; i++){
            for(int j = 0; j < n; j++){
                up[j][i] = up[up[j][i-1]][i-1];
            }
        }


        vector<int> ans;
        for(auto &q : queries){
            int a = q[0];
            int b = q[1];
            if(a == b){
                ans.push_back(0);
            }else if(check[a] != check[b]){
                ans.push_back(-1);
            }else{
                if(nums[b] < nums[a]){
                    swap(a, b);
                }
                // if diff btw them is lesser than maxDiff then push 1 directly
                if(nums[b] - nums[a] <= maxDiff){
                    ans.push_back(1);
                }else{
                    int jump = 0;
                    int u = start[a];
                    int v = start[b];

                    for(int i = LOG - 1; i >= 0; i--){
                        if(up[u][i] < v){
                            u = up[u][i];
                            jump += (1 << i);
                        }
                    }
                    ans.push_back(jump + 1);
                }
            }
        }
        return ans;
    }
};
