class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int c = pref.size();
        for(auto s : words){
            if(s.substr(0,c) == pref){
                ans++;
            }
        }
        return ans;
    }
};