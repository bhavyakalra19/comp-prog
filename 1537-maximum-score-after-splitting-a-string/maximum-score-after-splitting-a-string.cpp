class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                sum += 1;
            }
        }
        int ans = 0;
        int zr = 0;
        for(int i = 0; i < n-1; i++){
            if(s[i] == '1'){
                sum -= 1;
            }else{
                zr++;
            }
            ans = max(ans,sum + zr);
        }
        return ans;
    }
};