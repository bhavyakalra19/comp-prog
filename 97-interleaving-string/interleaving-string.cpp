class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1 + n2 != n3){
            return false;
        }
        vector<bool> prev(n2 + 1, false);
        for(int i = n1; i >= 0; i--){
            vector<bool> curr(n2 + 1, false);
            if(i == n1){
                curr[n2] = true;
            }
            for(int j = n2; j >= 0; j--){
                if(i < n1 && s1[i] == s3[i+j]){
                    curr[j] = prev[j];
                }
                if(j < n2 && s2[j] == s3[i+j]){
                    curr[j] = curr[j] | curr[j+1];
                }
            }
            prev = curr;
        }
        return prev[0]; 
    }
};