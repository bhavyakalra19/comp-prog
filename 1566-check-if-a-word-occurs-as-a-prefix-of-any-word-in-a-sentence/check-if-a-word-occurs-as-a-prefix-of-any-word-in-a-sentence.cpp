class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string s = "";
        int n = sentence.size();
        int m = searchWord.size();
        int i = 0;
        int step = 1;
        while(i < n){
            while(i < n && sentence[i] != ' '){
                s += sentence[i++];
                if(s.size() == m && s == searchWord){
                    return step;
                }
            }
            i++;
            s = "";
            step++;
        }
        return -1;
    }
};