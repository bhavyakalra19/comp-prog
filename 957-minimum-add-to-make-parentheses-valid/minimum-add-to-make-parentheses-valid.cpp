class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int check = 0;
        for(auto a : s){
            if(a == '('){
                ans += 1;
            }else if(ans > 0){
                ans -= 1;
                check += 2;
            }
        }
        return s.size() - check;
    }
};