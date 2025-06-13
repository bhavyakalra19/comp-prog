class Solution {
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        string curr = s1 + " " + s2;
        if(s1.size() == 1) return mp[curr] = false;
        if(mp.find(curr) != mp.end()) return mp[curr];
        int n = s1.size();
        bool ans = false;
        for(int i = 1; i < n; i++){
            ans |= isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i));
            if(ans) return mp[curr] = true;
            ans |= isScramble(s1.substr(0,i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0,n-i));
        }
        return mp[curr] = ans;
    }
};