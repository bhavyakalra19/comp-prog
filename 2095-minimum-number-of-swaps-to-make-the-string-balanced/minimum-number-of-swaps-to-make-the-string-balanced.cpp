class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        int check = 0;
        for(auto a : s){
            if(a == ']' && ans > 0){
                check += 2;
                ans -= 1;
            }else if(a == '['){
                ans++;
            }
        }
        int n = s.size() - check;
        cout << n << endl;
        return (n/2+1)/2;
    }
};