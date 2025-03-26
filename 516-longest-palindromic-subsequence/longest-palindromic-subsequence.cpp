class Solution {
public:

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        vector<int> prev(n+1,0);
        reverse(s2.begin(), s2.end());
        for(int i = 0; i < n; i++){
            vector<int> curr(n+1,0);
            for(int j = 0; j < n; j++){
                if(s[i] == s2[j]){
                    curr[j+1] = 1 + prev[j];
                }else{
                    curr[j+1] = max(curr[j], prev[j+1]);
                }
            }
            prev = curr;
        }
        
        return prev[n];
    }
};