class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> mp;
        vector<string> ans;
        for(auto t : tickets){
            mp[t[0]].push_back(t[1]);
        }
        for(auto &m : mp){
            sort(m.second.begin(), m.second.end());
        }
        stack<string> st;
        stack<string> main;
        st.push("JFK");
        while(!st.empty()){
            auto it = st.top();
            if(mp.find(it) == mp.end() || mp[it].size() == 0){
                st.pop();
                main.push(it);
            }else{
                string str = mp[it].front();
                mp[it].erase(mp[it].begin());
                st.push(str);
            }
        }
        while(!main.empty()){
            ans.push_back(main.top());
            main.pop();
        }
        return ans;
    }
};

// JFK -> MUC
// MUC -> LHR
// LHR -> SFO
// SFO -> SJC