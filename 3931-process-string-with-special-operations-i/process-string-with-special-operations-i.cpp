class Solution {
public:
    void reverseString(string &s){
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    string processStr(string s) {
        string ans = "";
        int i = 0;
        int n = s.size();
        while(i < n){
            if(s[i] == '%'){
                int cnt = 0;
                while(i < n && s[i] == '%'){
                    cnt++;
                    i++;
                }
                if(cnt % 2){
                    reverseString(ans);
                }
            }else if(s[i] == '#'){
                ans += ans;
                i++;
            }else if(s[i] == '*'){
                ans = ans.substr(0, ans.size() - 1);
                i++;
            }else{
                ans += s[i++];
            }
        }
        return ans;
    }
};