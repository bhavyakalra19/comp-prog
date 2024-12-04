class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            char curr = str1[i];
            if(curr == 'z'){
                curr = 'a';
            }else{
                ++curr;
            }
            if(str1[i] == str2[j] || curr == str2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j == m;
    }
};