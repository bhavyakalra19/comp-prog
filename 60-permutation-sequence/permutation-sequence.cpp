class Solution {
public:

    string getPermutation(int n, int k) {
        vector<int> fact(n+1,-1);
        fact[0] = 1;
        fact[1] = 1;
        for(int i = 1; i < n; i++){
            fact[i] = i * fact[i-1];
        }
        int curr = n-1;
        int ans;
        unordered_set<int> st;
        string result = "";
        while(result.size() < n){
            ans = 0;
            for(int i = 1; i <= n; i++){
                if(st.find(i) == st.end()){
                    if(ans + fact[curr] >= k){
                        result += to_string(i);
                        st.insert(i);
                        break;
                    }else{
                        ans += fact[curr];
                    }
                }
            }
            k -= ans;
            curr--;
        }
        return result;
    }
};