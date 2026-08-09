class Solution {
public:
    long long ans;

    int getHeight(vector<vector<int>> &graph, int i){
        if(graph[i].size() == 0){
            return 1;
        }
        int mx = 0;
        for(auto &a : graph[i]){
            mx = max(mx, getHeight(graph, a));
        }
        return 1 + mx;
    }

    void getAns(vector<vector<int>> &graph, int i, int h, vector<int> &nums){
        ans += 1LL * nums[i] * h;
        if(graph[i].size() == 0){
            return;
        }
        for(auto &a : graph[i]){
            getAns(graph, a, h-1, nums);
        }
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        ans = 0;
        int n = parent.size();
        vector<vector<int>> graph(n);
        for(int i = 1; i < n; i++){
            graph[parent[i]].push_back(i);
        }
        int height = getHeight(graph, 0);
        getAns(graph, 0, height, nums);
        return ans;
    }
};