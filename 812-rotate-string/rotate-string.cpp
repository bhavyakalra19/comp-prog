class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n != goal.size()){
            return false;
        }
        if(s == goal){
            return true;
        }
        for(int i = 0; i < n; i++){
            string s1 = s.substr(i);
            string s2 = s.substr(0,i);
            if(s1 + s2 == goal){
                return true;
            }
        }
        return false;
    }
};