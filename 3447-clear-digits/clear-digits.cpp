class Solution {
public:
    string clearDigits(string s) {
        int cnt = 0;
        int n = s.size();
        string ans = "";
        for(int i = n-1; i >= 0; i--){
            char a = s[i];
            if(s[i] >= '0' && s[i] <= '9'){
                cnt++;
            }else{
                if(cnt != 0){
                    cnt--;
                }else{
                    ans = s[i] + ans;
                }
            }
        }
        return ans;
    }
};