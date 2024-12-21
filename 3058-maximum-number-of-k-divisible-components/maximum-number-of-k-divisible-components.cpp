class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n < 2){
            return 1;
        }
        vector<int> degree(n);
        vector<vector<int>> graph(n);
        for(auto e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }
        int ans = 0;
        vector<long long> val(values.begin(), values.end());
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            degree[it]--;
            long long carry = 0;
            if(val[it] % k == 0){
                ans += 1;
            }else{
                carry = val[it];
            }
            for(auto g : graph[it]){
                if(degree[g] == 0){
                    continue;
                }
                degree[g]--;
                val[g] += carry;
                if(degree[g] == 1){
                    q.push(g);
                }
            }
        }
        return ans;
    }
};