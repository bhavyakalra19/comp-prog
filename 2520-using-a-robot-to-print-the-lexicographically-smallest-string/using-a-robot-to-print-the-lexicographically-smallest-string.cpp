class Solution {
public:
    bool checkLower(int a, vector<int> &check){
        for(int i = 0; i < a; i++){
            if(check[i] > 0) return true;
        }
        return false;
    }

    string robotWithString(string s) {
        int n = s.size();
        vector<int> check(26, 0);
        stack<char> st;
        string ans = "";
        for(int i = 0; i < n; i++){
            int a = s[i] - 'a';
            check[a]++;
        }
        int i = 0;
        while(i < n){
            int a = s[i] - 'a';
            if(!st.empty() && st.top() < s[i] && !checkLower(st.top() - 'a', check)){
                ans += st.top();
                st.pop();
            }else if(checkLower(a, check)){
                check[a]--;
                st.push(s[i++]);
            }else{
                if(!st.empty() && st.top() <= s[i]){
                    ans += st.top();
                    st.pop();
                }else{
                    check[a]--;
                    ans += s[i++];
                }
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
