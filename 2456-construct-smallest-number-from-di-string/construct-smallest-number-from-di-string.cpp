class Solution {
public:
    string ans = "";
    void getAns(string s, int idx, string &pattern, vector<bool> &check, int prev){
        if(ans != "") return;
        if(idx == pattern.size()){
            ans = s;
            return;
        }
        for(int i = 1; i < 10; i++){
            if(check[i]){
                if((pattern[idx] == 'I' && i > prev) || (pattern[idx] == 'D' && i < prev)){
                    check[i] = false;
                    getAns(s + to_string(i), idx + 1, pattern, check, i);
                    check[i] = true;
                }
            }
        }
    }

    string smallestNumber(string pattern) {
        vector<bool> check(10,true);
        for(int i = 1; i < 10; i++){
            check[i] = false;
            getAns(to_string(i), 0, pattern, check, i);
            check[i] = true;
        }
        return ans;
    }
};