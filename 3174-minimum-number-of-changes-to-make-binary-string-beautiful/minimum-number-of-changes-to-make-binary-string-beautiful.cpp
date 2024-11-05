class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int ans = 0;
        int i = 0;
        while(i < n){
            string check = s.substr(i,2);
            if(check[0] != check[1]){
                ans += 1;
            }
            i += 2;
        }
        return ans;
    }
};