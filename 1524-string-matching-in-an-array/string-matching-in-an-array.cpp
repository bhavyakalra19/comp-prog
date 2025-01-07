class Solution {
public:
    vector<int> checkKmp(string s){
        int n = s.size();
        vector<int> check(n,0);
        int j = 0;
        for(int i = 1; i < n; i++){
            while(1){
                if(s[i] == s[j]){
                    check[i] = j+1;
                    j++;
                    break;
                }else{
                    if(j == 0){
                        check[i] = 0;
                        break;
                    }
                    j = check[j-1];
                }
            }
        }
        return check;
    }

    bool compareKmp(string s1, string s2, vector<int> check){
        int j = 0;
        int n = s1.size();
        for(int i = 0; i < n; i++){
            while(1){
                if(s1[i] == s2[j]){
                    j++;
                    break;
                }else{
                    if(j == 0){
                        break;
                    }
                    j = check[j-1];
                }
            }
            if(j == s2.size()){
                return true;
            }
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> cmp;
        for(auto s : words){
            cmp.push_back(checkKmp(s));
        }
        unordered_set<string> st;
        for(int i = 0; i < n - 1; i++){
            for(int j = i+1; j < n; j++){
                if(words[i].size() < words[j].size()){
                    if(compareKmp(words[j], words[i], cmp[i])){
                        st.insert(words[i]);
                    }
                }else{
                    if(compareKmp(words[i], words[j], cmp[j])){
                        st.insert(words[j]);
                    }
                }
            }
        }
        vector<string> ans;
        for(auto a : st){
            ans.push_back(a);
        }
        return ans;
    }
};