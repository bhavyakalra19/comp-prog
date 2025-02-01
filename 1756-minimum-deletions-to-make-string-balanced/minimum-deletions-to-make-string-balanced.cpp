class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int sm = 0;
        int next = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == 'b'){
                next = min(1 + next, sm);
            }else{
                sm++;
            }
        }
        return next;
    }
};