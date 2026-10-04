class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0;
        int mx = 0;
        for(auto &a : s){
            if(a == '*'){
                mx++;
                if(mn > 0){
                    mn--;
                }
            }else if(a == '('){
                mx++;
                mn++;
            }else{
                if(mx == 0) return false;
                mx--;
                if(mn > 0){
                    mn--;
                }
            }
        }
        return mn == 0;
    }
};