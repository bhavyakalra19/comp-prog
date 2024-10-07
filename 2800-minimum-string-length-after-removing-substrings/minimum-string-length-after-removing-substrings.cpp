class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto a : s){
            if(!st.empty() && a == 'B' && st.top() == 'A'){
                st.pop();
            }else if(!st.empty() && a == 'D' && st.top() == 'C'){
                st.pop();
            }else{
                st.push(a);
            }
        }
        return st.size();
    }
};