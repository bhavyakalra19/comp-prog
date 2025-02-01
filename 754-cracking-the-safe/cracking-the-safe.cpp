class Solution {
public:
    int total;
    string ans;
    bool getAns(string check, unordered_set<string> &st, int k, int n){
        if(st.size() == total){
            ans = check;
            return true;
        }
        string prev = check.substr(check.size() - n + 1);
        for(int i = 0; i < k; i++){
            string next = prev + to_string(i);
            if(st.find(next) == st.end()){
                st.insert(next);
                if(getAns(check + to_string(i), st, k, n)){
                    return true;
                }else{
                    st.erase(next);
                }
            }
        }
        return false;
    }

    string crackSafe(int n, int k) {
        unordered_set<string> st;
        string a = "";
        ans = "";
        total = pow(k,n);
        for(int i = 0; i < n; i++){
            a += 0 + '0';
        }
        st.insert(a);
        getAns(a,st,k,n);
        return ans;
    }
};