class Solution {
public:
    string ans;
    void getAns(string s, int &n, int &k, int idx){
        if(ans != "") return;
        if(idx == n){
            --k;
            if(k == 0) ans = s;
            return;
        }

        for(int i = 0; i < 3; i++){
            char c = i + 'a';
            if(idx == 0 || s[idx - 1] != c){
                getAns(s + c, n, k, idx + 1);
            }
        }
    }

    string getHappyString(int n, int k) {
        ans = "";
        getAns("", n, k, 0);
        return ans;
    }
};