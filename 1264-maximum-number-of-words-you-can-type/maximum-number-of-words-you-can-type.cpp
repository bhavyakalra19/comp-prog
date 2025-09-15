class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> check(26, 0);
        for(auto &a : brokenLetters){
            check[a - 'a'] = true;
        }
        bool add = true;
        int ans = 0;
        for(auto &a : text){
            if(a == ' '){
                if(add) ans += 1;
                add = true;
            }else if(check[a - 'a']){
                add = false;
            }
        }
        return add == true ? ans + 1: ans;
    }
};