class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2 != 0){
            return false;
        }
        int fc = 0;
        int oc = 0;
        for(int i = 0; i < n; i++){
            if(locked[i] == '0'){
                fc++;
            }else if(s[i] == '('){
                oc++;
            }else{
                if(oc > 0){
                    oc--;
                }else if(fc > 0){
                    fc--;
                }else{
                    return false;
                }
            }
        }
        fc = 0;
        oc = 0;
        for(int i = n-1; i >= 0; i--){
            if(locked[i] == '0'){
                fc++;
            }else if(s[i] == ')'){
                oc++;
            }else{
                if(oc > 0){
                    oc--;
                }else if(fc > 0){
                    fc--;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

