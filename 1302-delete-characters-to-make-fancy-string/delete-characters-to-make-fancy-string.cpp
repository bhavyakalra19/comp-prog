class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(i < n-2 && s[i] == s[i+1] && s[i+1] == s[i+2]) continue;
            ans += s[i];
        }
        return ans;
    }
};