class Solution {
public:
    vector<int> levels;
    vector<int> check;
    vector<vector<int>> adj;
    int ans;
    int getXor(int curr, int par, int level, vector<int> &nums){
        int total = nums[curr];
        levels[curr] = level;
        for(auto &a : adj[curr]){
            if(a != par){
                total ^= getXor(a, curr, level + 1, nums);
            }
        }
        check[curr] = total;
        return total;
    }

    void getDfs(int x, int y, int curr, int par, vector<int> &nums, int lvl){
        for(auto &a : adj[curr]){
            if(a != par){
                int a1 = y ^ check[a];
                int a2 = check[a];
                if(levels[a] == lvl){
                    a1 = check[curr] ^ x;
                    a2 = y ^ a1;
                }
                int mx = max(x, max(a1, a2));
                int mn = min(x, min(a1, a2));
                ans = min(ans, mx - mn);
                getDfs(x, y, a, curr, nums, lvl - 1);
            }
        }
    }

    void getAns(int x, int y, int curr, int par){
        for(auto &a : adj[curr]){
            if(a != par){
                int a1 = y ^ check[a];
                int a2 = check[a];
                int mx = max(x, max(a1, a2));
                int mn = min(x, min(a1, a2));
                ans = min(ans, mx - mn);
                getAns(x, y, a, curr);
            }
        }
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        adj.resize(n);
        check.resize(n);
        levels.resize(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int total = getXor(0, 0, 0, nums);
        ans = INT_MAX;
        for(auto &e : edges){
            int a = e[0];
            int b = e[1];
            if(levels[a] > levels[b]){
                swap(a, b);
            }
            getDfs(check[b], total ^ check[b], a, b, nums, levels[a] - 1);
            getDfs(total ^ check[b], check[b], b, a, nums, levels[b] - 1);
        }
        return ans;
    }
};
