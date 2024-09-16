class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int mx = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(1);
            }else{
                if(!st.empty() && st.top() == 1){
                    st.pop();
                    st.push(2);
                }else if(!st.empty() && st.top() > 1){
                   auto it = st.top();
                   st.pop();
                   if(!st.empty() && st.top() == 1){
                    st.pop();
                    st.push(it + 2);
                   }else{
                    st.push(-1);
                   }
                }else{
                    st.push(-1);
                }
                if(st.top() > 1){
                    auto it = st.top();
                    st.pop();
                    if(!st.empty() && st.top() > 1){
                        auto its = st.top();
                        st.pop();
                        st.push(it + its);
                    }else{
                        st.push(it);
                    }
                }
            }
            mx = max(mx,st.top());
        }
        return mx == 1 ? 0 : mx;
    }
};