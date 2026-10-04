class Solution {
public:
    bool checkValidString(string s) {
        // check both sides if open and close can be < 0
        int n = s.size();
        int open = 0;
        for(auto &a: s){
            if(a == '(' || a == '*'){
                open++;
            }else{
                open--;
            }
            if(open < 0) return false;
        }
        int close = 0;
        for(int i = n-1; i >= 0; i--){
            char a = s[i];
            if(a == ')' || a == '*'){
                close++;
            }else{
                close--;
            }
            if(close < 0) return false;
        }
        return true;
    }
};