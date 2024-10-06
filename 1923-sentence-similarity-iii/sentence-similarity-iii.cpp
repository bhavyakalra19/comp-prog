class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        int ci = 0;
        int i = 0;
        while(i < m && i < n){
            if(s1[i] == ' ' && s2[i] == ' '){
                ci = i;
            }
            if(s1[i] != s2[i]){
                break;
            }
            i++;
        }
        if(i == m && i == n){
            ci = i;
        }
        if(i == m && s2[i] == ' '){
            ci = i;
        }
        if(i == n && s1[i] == ' '){
            ci = i;
        }
        cout << ci << endl;
        int j1 = m - 1;
        int j2 = n - 1;
        while(j1 >= ci && j2 >= ci && s1[j1] == s2[j2]){
            j1--;
            j2--;
        }
        if((j1 == -1 && s2[j2] != ' ') || (j2 == -1 && s1[j1] != ' ')){
            return false;
        }
        return (j1 + 1 == ci || j2 + 1 == ci) ? true : false;
    }
};