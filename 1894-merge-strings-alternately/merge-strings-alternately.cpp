class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0;
        int m = word1.size();
        int n = word2.size();
        while(i < m || i < n){
            if(i < m){
                ans += word1[i];
            }
            if(i < n){
                ans += word2[i];
            }
            i++;
        }
        return ans;
    }
};