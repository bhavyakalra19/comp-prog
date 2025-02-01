class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;
        for(auto t : tickets){
            mp[t[0]].push(t[1]);
        }
        string start = "JFK";
        stack<string> st;
        st.push(start);
        vector<string> curr;
        vector<vector<string>> ans;
        while(!st.empty()){
            auto it = st.top();
            if(!mp[it].empty()){
                st.push(mp[it].top());
                mp[it].pop();
            }else{
                curr.push_back(it);
                st.pop();
            }
        }
        reverse(curr.begin(), curr.end());
        return curr;
    }
};