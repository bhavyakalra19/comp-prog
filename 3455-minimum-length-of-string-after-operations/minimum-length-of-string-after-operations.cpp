class Solution {
public:
    int minimumLength(string s) {
        vector<int> check(26,0);
        int cnt = 0;
        for(auto a : s){
            check[a - 'a']++;
            cnt++;
            if(check[a - 'a'] == 3){
                cnt -= 2;
                check[a - 'a'] -= 2;
            }
        }
        return cnt;
    }
};