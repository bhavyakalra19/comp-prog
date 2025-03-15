class Solution {
public:
    void getAns(string &s, unordered_set<string> &st, int idx, string curr, int &ans){
        if(idx == s.size()){
            int a = 0;
            if(curr != "" && st.find(curr) == st.end()) a = 1; 
            ans = max(ans, (int)(st.size()) + a);
            return;
        }
        getAns(s, st, idx + 1, curr + s[idx], ans);
        if(curr != "" && st.find(curr) == st.end()){
            st.insert(curr);
            getAns(s, st, idx, "", ans);
            st.erase(curr);
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int ans = 0;
        getAns(s, st, 0, "", ans);
        return ans;
    }
};