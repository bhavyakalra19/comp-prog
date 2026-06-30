class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0;
        int b = 0;
        int c = 0;
        int i = 0;
        int n = s.size();
        int ans = 0;
        int prev = 0;
        int j = 0;
        while(i < n){
            while(i < n && (a == 0 || b == 0 || c == 0)){
                if(s[i] == 'a'){
                    a++;
                }else if(s[i] == 'b'){
                    b++;
                }else{
                    c++;
                }
                i++;
            }
            int j = prev;

            while(prev < n && (a > 0 && b > 0 && c > 0)){
                if(s[prev] == 'a'){
                    a--;
                }else if(s[prev] == 'b'){
                    b--;
                }else{
                    c--;
                }
                prev++;
            }

            int right = n - i + 1;
            int left = prev - j;
            ans += left * right;
            
        }
        return ans;
    }
};


// a a a b c a a b c
