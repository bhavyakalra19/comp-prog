class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int n = s.size();
        int p = part.size();
        char end = part[p-1];
        for(auto a : s){
            ans += a;
            if(a == end && ans.size() >= p && ans.substr(ans.size() - p) == part){
                ans = ans.substr(0, ans.size() - p);
            }
        }
        return ans;
    }
};

