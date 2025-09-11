class Solution {
public:
    string sortVowels(string s) {
        vector<int> index;
        vector<int> vowel;
        int n = s.size();
        for(int i = 0; i < s.size(); i++){
            char a = s[i];
            if(a == 'i' || a == 'a' || a == 'e' || a == 'o' || a == 'u' || a == 'I' || a == 'A' || a == 'E' || a == 'O' || a == 'U'){
                index.push_back(i);
                vowel.push_back(a - 'A');
            }
        }
        sort(vowel.begin(), vowel.end());
        for(int i = 0; i < index.size(); i++){
            s[index[i]] = vowel[i] + 'A';
        }
        return s;
    }
};