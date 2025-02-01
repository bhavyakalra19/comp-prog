class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> check(n+1,0);
        int sm = 0;
        // for(int i = n - 1; i >= 0; i--){
        //     if(s[i] == 'a'){
        //         sm += 1;
        //     }
        // }
        int next = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] != 'a'){
                next = min(1 + next, sm);
            }else{
                sm++;
            }
        }
        return next;
    }
};