class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string ans = "";
        int i = 0;
        int count;
        while(i < n){
            count = 1;
            char c = word[i];
            while(i < n-1 && word[i] == word[i+1]){
                i++;
                count++;
            }
            while(count > 9){
                ans += '9';
                ans += c;
                count -= 9;
            }
            if(count > 0){
                ans += to_string(count);
                ans += c;
            }
            i++;
        }
        return ans;
    }
};