class Solution {
public:
    string ans = "";
    void getAns(string s, int idx, string &pattern, vector<bool> &check, int prev){
        if(ans != "") return;
        if(idx == pattern.size() + 1){
            ans = s;
            return;
        }
        for(int i = 1; i < 10; i++){
            if(check[i]){
                if(idx == 0 || (pattern[idx - 1] == 'I' && i > prev) || (pattern[idx - 1] == 'D' && i < prev)){
                    check[i] = false;
                    getAns(s + to_string(i), idx + 1, pattern, check, i);
                    check[i] = true;
                }
            }
        }
    }

    string smallestNumber(string pattern) {
        vector<bool> check(10,true);
        // for(int i = 1; i < 10; i++){
        //     check[i] = false;
            getAns("", 0, pattern, check, -1);
        //     check[i] = true;
        // }
        return ans;
    }
};