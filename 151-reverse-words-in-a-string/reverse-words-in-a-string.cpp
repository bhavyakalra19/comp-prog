class Solution {
public:
    void rev(string &s, int a, int b){
        while(a < b){
            swap(s[a++], s[b--]);
        }
    }

    string reverseWords(string s) {
        string ans = "";
        reverse(s.begin(), s.end());
        int n = s.size();
        int i = 0;
        int j = 0;
        while(i < n){
            while(i < n && s[i] == ' '){
                i++;
            }
            j = i;
            while(i < n && s[i] != ' '){
                i++;
            }
            if(j == i){
                continue;
            }
            rev(s,j,i-1);
            if(ans == ""){
                ans = s.substr(j,i - j);
                continue;
            }
            ans += " " + s.substr(j,i - j);
        }
        return ans;
    }
};