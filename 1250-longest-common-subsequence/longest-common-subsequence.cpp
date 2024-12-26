class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        // return getAns(text1, text2, text1.size() - 1, text2.size() - 1, dp);
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1,0);
        for(int i = 0; i < n; i++){
            vector<int> curr(m+1,0);
            for(int j = 0; j < m; j++){
                if(text1[i] == text2[j]){
                    curr[j+1] = 1 + prev[j];
                }else{
                    curr[j+1] = max(curr[j], prev[j+1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};