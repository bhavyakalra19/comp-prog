class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        int i = 0;
        int j = 0;
        int m = s1.size();
        int n = s2.size();
        unordered_map<string,int> mp;
        string a;
        vector<string> ans;
        while(i < m){
            a = "";
            while(i < m && s1[i] != ' '){
                a += s1[i++];
            }
            i++;
            mp[a] += 1;
        }
        while(j < n){
            a = "";
            while(j < n && s2[j] != ' '){
                a += s2[j++];
            }
            j++;
            mp[a] += 1;
        }

        for(auto a : mp){
            if(a.second == 1){
                ans.push_back(a.first);
            }
        }
        return ans;
    }
};