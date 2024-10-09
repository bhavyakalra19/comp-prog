class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        int check = 0;
        for(auto a : s){
            if(a == '['){
                ans++;
            }else if(ans > 0){
                check += 2;
                ans--;
            }
        }
        int n = s.size() - check;
        return (n/2+1)/2;
    }
};