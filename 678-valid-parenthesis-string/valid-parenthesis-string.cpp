class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int mn = 0;
        int mx = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                mn++;
                mx++;
            }else if(s[i] == '*'){
                if(mn > 0) mn--;
                mx++;
            }else{
                if(mn > 0) mn--;
                mx--;
                if(mx < 0) return false;
            }
        }
        return mn == 0;
    }
};