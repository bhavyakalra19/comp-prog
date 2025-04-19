class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                cnt++;
            }else if(s[i] == ')'){
                if(cnt == 0){
                    continue;
                }else{
                    cnt--;
                }
            }
            st.push(s[i]);
        }
        cnt = 0;
        string ans = "";
        while(!st.empty()){
            if(st.top() == '('){
                if(cnt == 0){
                    st.pop();
                    continue;
                }else{
                    cnt--;
                }
            }else if(st.top() == ')'){
                cnt++;
            }
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};