class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int i = 0;
        int ans = 1;
        while(i < n){
            int j = i;
            while(i < n && word[i] == word[j]){
                i++;
            }
            ans += i - j - 1;
        }
        return ans;
    }
};