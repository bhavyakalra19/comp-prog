class Solution {
public:
    int maxScore(string s) {
        int sum = 0;
        for(auto a : s){
            if(a == '1'){
                sum++;
            }
        }
        int mx = 0;
        int zr = 0;
        int n = s.size();
        for(int i = 0; i < n-1; i++){
            if(s[i] == '1'){
                sum--;
            }else{
                zr++;
            }
            mx = max(mx,sum + zr);
        }
        return mx;
    }
};