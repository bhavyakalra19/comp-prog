class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long ans = 0;
        long long count = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0'){
                count++;
            }else{
                ans += count;
            }
        }
        return ans;
    }
};