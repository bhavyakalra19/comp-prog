class Solution {
public:

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> check(n+1,0);
        unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < n; i++){
            if(st.find(words[i][0]) != st.end() && st.find(words[i][words[i].size() - 1]) != st.end()){
                check[i+1] = check[i] + 1;
            }else{
                check[i+1] = check[i];
            }
        }
        vector<int> ans;
        for(auto q : queries){
            ans.push_back(check[q[1]+1] - check[q[0]]);
        }
        return ans;
    }
};