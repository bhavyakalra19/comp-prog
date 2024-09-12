class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        if(allowed.size() == 0 || words.size() == 0){
            return 0;
        }
        vector<int> check(26,0);
        for(int i = 0; i < allowed.size(); i++){
            check[allowed[i] - 'a'] = 1;
        }
        int n = words.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int b = 1;
            for(auto a : words[i]){
                if(check[a - 'a'] == 0){
                    b = 0;
                    break;
                }
            }
            ans += b;
        }
        return ans;
    }
};