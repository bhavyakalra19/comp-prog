class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        s1.push_back(' ');
        s2.push_back(' ');
        vector<string> check1;
        vector<string> check2;
        string ans = "";
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == ' '){
                check1.push_back(ans);
                ans = "";
            }else{
                ans += s1[i];
            }
        }

        for(int i = 0; i < s2.size(); i++){
            if(s2[i] == ' '){
                check2.push_back(ans);
                ans = "";
            }else{
                ans += s2[i];
            }
        }
        int m1 = 0, m2 = 0;
        int n1 = check1.size() - 1;
        int n2 = check2.size() - 1;
        while(m1 <= n1 && m2 <= n2){
            if(check1[m1] == check2[m2]){
                m1++;
                m2++;
            }else if(check1[n1] == check2[n2]){
                n1--;
                n2--;
            }else{
                break;
            }
        }
        return (n1 + 1 == m1 || n2 + 1 == m2) ? true : false;
    }
};