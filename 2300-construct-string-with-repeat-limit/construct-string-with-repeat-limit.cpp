class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        vector<int> check(26,0);
        for(auto a : s){
            check[a - 'a'] += 1;
        }
        int i = 0;
        string ans = "";
        int prev = -1;
        int j;
        while(i < n){
            j = 25;
            int limit = repeatLimit;
            while(j >= 0 && (check[j] == 0 || j == prev)){
                if(prev == j && check[j] > 0){
                    limit = 1;
                }
                j--;
            }
            if(j < 0){
                break;
            }
            for(int a = 0; a < limit && check[j] > 0; a++){
                ans += j + 'a';
                check[j] -= 1;
                i++;
                prev = j;
            }
        }
        return ans;
    }
};