class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                if(st.empty() || s[st.top()] == ')'){
                    st.push(i);
                }else{
                    st.pop();
                    int last = st.empty() ? -1 : st.top();
                    ans = max(ans, i - last);
                }
            }
        }
        return ans;
    }
};