class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> grp;
        unordered_map<int,int> mp;
        vector<vector<int>> ans;
        for(auto p : pairs){
            grp[p[0]].push_back(p[1]);
            mp[p[0]]++;
            mp[p[1]]--;
        }
        int startNode = pairs[0][0];
        for(auto m : mp){
            if(m.second == 1){
                startNode = m.first;
                break;
            }
        }
        vector<int> check;
        stack<int> st;
        st.push(startNode);

        while(!st.empty()){
            auto start = st.top();
            if(grp[start].size() != 0){
                int next = grp[start].back();
                grp[start].pop_back();
                st.push(next);
            }else{
                check.push_back(start);
                st.pop();
            }
        }
        for(int i = 1; i < check.size(); i++){
            ans.push_back({check[i],check[i-1]});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};