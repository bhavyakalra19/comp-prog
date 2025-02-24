class Solution {
public:
    bool check = false;
    void dfs(stack<int> &st, vector<vector<int>> &gp, int idx, vector<int> &steps, int prev){
        if(check) return;
        if(idx == 0){
            int cnt = st.size();
            st.push(0);
            while(!st.empty()){
                steps[st.top()] = cnt;
                st.pop();
                cnt--;
            }
            check = true;
            return;
        }
        st.push(idx);
        for(auto a : gp[idx]){
            if(a != prev){
                dfs(st, gp, a, steps, idx);
            }
        }
        if(!st.empty()) st.pop();
    }

    int getAns(vector<vector<int>> &gp, int idx, int prev, vector<int> &steps, vector<int> &amount, int cnt){
        int ans = INT_MIN;
        for(auto a : gp[idx]){
            if(prev != a){
                ans = max(ans, getAns(gp, a, idx, steps, amount, cnt + 1));
            }
        }
        if(ans == INT_MIN) ans = 0;
        if(steps[idx] == cnt){
            ans += amount[idx] / 2;
        }else if(cnt < steps[idx]){
            ans += amount[idx];
        }
        return ans;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> gp(n);
        for(auto e : edges){
            gp[e[0]].push_back(e[1]);
            gp[e[1]].push_back(e[0]);
        }
        vector<int> steps(n, n + 2);
        stack<int> st;
        dfs(st, gp, bob, steps, -1);
        return getAns(gp, 0, -1, steps, amount, 0);
    }
};