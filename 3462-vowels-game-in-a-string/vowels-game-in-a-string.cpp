class Solution {
public:
    bool doesAliceWin(string s) {
        for(auto &a : s) if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
        return false;       
    }
};
