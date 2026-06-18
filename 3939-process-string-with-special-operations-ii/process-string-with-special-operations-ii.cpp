class Solution {
public:
    void createArray(string s, long long &curr){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                curr = max(0LL, curr - 1);
            }else if(s[i] == '#'){
                curr = 2 * curr;
            }else if(s[i] != '%'){
                curr += 1;
            }
        }
    }

    // check string length at each step
    // backtrack k from back of string
    // if s[i] == '#' it means we will remove (curr_len at s[i] / 2) if k >= (curr_len/2)
    // if s[i] == '%' it means reverse k position accoring to curr_len at s[i], coz before this operaton k would be pointing to reverse of that position
    // if s[i] is letter and k == curr_len - 1, that is your answer


    char processStr(string s, long long k) {
        int n = s.size();
        long long curr = 0;
        createArray(s, curr);
        if(k >= curr) return '.';

        for(int i = n-1; i >= 0; i--){
            if(s[i] == '*'){
                curr += 1;
                continue;
            }else if(s[i] == '#'){
                long long len = curr / 2;
                if(k >= len) k = k - len;
                curr /= 2;
            }else if(s[i] == '%'){
                k = curr - k - 1;
            }else{
                if(k == (curr - 1)){
                    return s[i];
                }
                curr -= 1;
            }
        }
        return s[0];
    }
};