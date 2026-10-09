class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            char a = s[i];
            if(a == '('){
                open++;
            }else{
                if(i + 1 < n && s[i+1] == ')'){
                    i++;
                }else{
                    ans++;
                }
                if(open > 0){
                    open--;
                }else{
                    ans++;
                }
            }
        }
        return open * 2 + ans;
    }
};