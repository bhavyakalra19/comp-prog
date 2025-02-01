class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int sm = 0;
        int next = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == 'a'){
                sm++;
            }else{
                next = min(sm, 1 + next);
            }
        }
        return next;
    }
};