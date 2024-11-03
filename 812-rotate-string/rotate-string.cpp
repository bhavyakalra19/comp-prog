class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size();
        int n = goal.size();
        if(m != n){
            return false;
        }
        for(int i = 0; i < m; i++){
            string s1 = s.substr(i);
            string s2 = s.substr(0,i);
            if(s1 + s2 == goal){
                return true;
            }
        }
        return false;
    }
};