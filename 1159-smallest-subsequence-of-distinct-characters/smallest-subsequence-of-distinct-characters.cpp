class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> check(26);
        for(int i = 0; i < n; i++){
            int x = s[i] - 'a';
            check[x] = i;
        }
        stack<int> st;
        vector<bool> pres(26, 0);
        for(int i = 0; i < n; i++){
            int x = s[i] - 'a';
            if(!pres[x]){
                while(!st.empty() && st.top() > x && check[st.top()] > i){
                    int y = st.top();
                    st.pop();
                    pres[y] = false;
                }
                pres[x] = true;
                st.push(x);
            }
        }
        string str = "";
        while(!st.empty()){
            str = (char)(st.top() + 'a') + str;
            st.pop();
        }
        return str;
    }
};

// you have to choose exactly once

// a -> 1
// b ->

// a c b

// bdaba
// b d a