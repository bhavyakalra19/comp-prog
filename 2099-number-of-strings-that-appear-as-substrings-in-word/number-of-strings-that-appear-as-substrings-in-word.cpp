class Solution {
public:
    bool check(string word, string pattern) {
        //KMP
        int n = word.size();
        vector<int> check(n, 0);
        int j = 0;
        for(int i = 1; i < n; i++){
            while(1){
                if(word[i] == word[j]){
                    j++;
                    check[i] = j;
                    break;
                }else{
                    if(j == 0){
                        check[i] = 0;
                        break;
                    }
                    j = check[j - 1];
                }
            }
        }
        j = 0;
        for(auto &a : pattern){
            while(1){
                if(a == word[j]){
                    j++;
                    break;
                }else{
                    if(j == 0){
                        break;
                    }
                    j = check[j-1];
                }
            }
            if(j == n){
                return true;
            }
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(auto &pattern : patterns){
            if(check(pattern, word)) ans++;
        }
        return ans;
    }
};