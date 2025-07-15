class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        int cnt = 0;
        int vw = 0;
        for(auto a : word){
            if(a >= '0' && a <= '9') continue;
            if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')){
                if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U'){
                vw++;
                }else{
                    cnt++;
                }
            }else{
                return false;
            }
        }
        if(cnt == 0 || vw == 0) return false;
        return true;
    }
};