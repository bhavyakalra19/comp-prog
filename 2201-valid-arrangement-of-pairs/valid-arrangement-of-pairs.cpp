class Solution {
public:
    // void dfs(unordered_map<int,stack<int>> &mp, vector<int> &curr, int idx){
    //     while(!mp[idx].empty()){
    //         int a = mp[idx].top();
    //         mp[idx].pop();
    //         dfs(mp,curr,a);
    //     }
    //     curr.push_back(idx);
    // }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,stack<int>> mp;
        unordered_map<int,int> cnt;
        vector<int> curr;
        vector<vector<int>> ans;
        stack<int> st;
        for(auto p : pairs){
            cnt[p[0]]++;
            cnt[p[1]]--;
            mp[p[0]].push(p[1]);
        }
        int start = pairs[0][0];
        for(auto m : cnt){
            if(m.second == 1){
                start = m.first;
            }
        }
        st.push(start);
        while(!st.empty()){
            auto it = st.top();
            if(!mp[it].empty()){
                int c = mp[it].top();
                mp[it].pop();
                st.push(c);
            }else{
                st.pop();
                curr.push_back(it);
            }
        }
        for(int i = curr.size() - 1; i > 0; i--){
            ans.push_back({curr[i],curr[i-1]});
        }
        return ans;
    }
};