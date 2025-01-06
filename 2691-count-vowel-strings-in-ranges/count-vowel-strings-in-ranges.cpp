class Solution {
public:
    unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
    bool checkString(string s){
        int n = s.size() - 1;
        if(st.find(s[0]) != st.end() && st.find(s[n]) != st.end()){
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> check(n+1);
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(checkString(words[i])){
                sum += 1;
            }
            check[i+1] = sum;
        }
        vector<int> ans;
        for(auto q : queries){
            ans.push_back(check[q[1]+1] - check[q[0]]);
        }
        return ans;
    }
};