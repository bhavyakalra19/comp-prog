class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(m > n){
            return false;
        }
        vector<int> check(26,0);
        vector<int> curr(26,0);
        for(int i = 0; i < m; i++){
            check[s1[i] - 'a']++;
            curr[s2[i] - 'a']++;
        }
        for(int i = m; i < n; i++){
            if(check == curr){
                return true;
            }
            curr[s2[i - m] - 'a']--;
            curr[s2[i] - 'a']++;
        }
        return check == curr;
    }
};