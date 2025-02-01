class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> check(n+1,0);
        int sm = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'a'){
                sm += 1;
            }
            check[i] = sm;
        }
        int next = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] != 'a'){
            //     next = next;
            // }else{
                next = min(1 + next, check[i+1]);
            }
        }
        return next;
    }
};