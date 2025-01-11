class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n < k){
            return false;
        }
        vector<int> check(26,0);
        for(auto a : s){
            check[a - 'a']++;
        }
        int count = 0;
        for(int i = 0; i < 26; i++){
            if(check[i] % 2 != 0){
                count++;
            }
        }
        return count <= k;
    }
};
