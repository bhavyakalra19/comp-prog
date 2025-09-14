class Solution {
public:
    pair<string,string> convertString(string s){
        string lower = s;
        for(int i = 0; i < s.size(); i++){
            char a = s[i];
            if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
                s[i] = '1';
            }else if(a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U'){
                lower[i] = (lower[i]  - 'A') + 'a';
                s[i] = '1';
            }else if(a - 'a' < 0){
                lower[i] = (lower[i]  - 'A') + 'a';
                s[i] = (s[i] - 'A') + 'a';
            }
        }
        return {lower, s};
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string,string> mp;
        unordered_map<string,string> similar;
        unordered_map<string,string> lower;
        vector<string> ans;
        for(auto &a : wordlist){
            pair<string,string> s = convertString(a);
            similar[a] = a; 
            if(lower.find(s.first) == lower.end()){
                lower[s.first] = a;
            }
            if(mp.find(s.second) == mp.end()){
                mp[s.second] = a;
            }
        }
        for(auto &a : queries){
            if(similar.find(a) != similar.end()){
                ans.push_back(a);
            }else{
                pair<string,string> s = convertString(a);
                if(lower.find(s.first) != lower.end()){
                    ans.push_back(lower[s.first]);
                }else if(mp.find(s.second) != mp.end()){
                    ans.push_back(mp[s.second]);
                }else{
                    ans.push_back("");
                }
            }
        }
        return ans;
    }
};