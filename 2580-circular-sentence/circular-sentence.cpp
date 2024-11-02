class Solution {
public:
    bool isCircularSentence(string sentence) {
        char start = sentence[0];
        char curr;
        int n = sentence.size();
        int i = 0;
        while(i < n){
            while(i < n && sentence[i] != ' '){
                curr = sentence[i];
                i++;
            }
            i++;
            if(i < n && curr != sentence[i]){
                return false;
            }
        }
        return start == curr;
    }
};