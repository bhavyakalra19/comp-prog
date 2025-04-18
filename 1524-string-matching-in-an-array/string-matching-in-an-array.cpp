class Solution {
public:
    vector<int> checkKmp(string s){
        int n = s.size();
        vector<int> check(n,0);
        int j = 0;
        for(int i = 1; i < n; i++){
            while(1){
                if(s[i] == s[j]){
                    check[i] = j+1;
                    j++;
                    break;
                }else{
                    if(j == 0){
                        check[i] = 0;
                        break;
                    }
                    j = check[j-1];
                }
            }
        }
        return check;
    }

    bool compareKmp(string s1, string s2){
        vector<int> check;
        check = checkKmp(s2);
        int j = 0;
        int n = s1.size();
        for(int i = 0; i < n; i++){
            while(1){
                if(s1[i] == s2[j]){
                    j++;
                    break;
                }else{
                    if(j == 0){
                        break;
                    }
                    j = check[j-1];
                }
            }
            if(j == s2.size()){
                return true;
            }
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string &s1, const string &s2){
            return s1.size() < s2.size();
        });
        vector<string> ans;
        for(int i = 0; i < n - 1; i++){
            for(int j = i+1; j < n; j++){
                if(compareKmp(words[j], words[i])){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};