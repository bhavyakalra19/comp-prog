class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string s1 = s;
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == '9'){
            i++;
        }
        char curr = s[i];
        while(i < n){
            if(s[i] == curr){
                s[i] = '9';
            }
            i++;
        }
        int a = stoi(s);
        if(s1[0] == '1'){
            i = 0;
            while(i < n && (s1[i] == '1' || s1[i] == '0')){
                i++;
            }
            curr = s1[i];
            while(i < n){
                if(s1[i] == curr){
                    s1[i] = '0';
                }
                i++;
            }
        }else{
            curr = s1[0];
            i = 0;
            while(i < n){
                if(s1[i] == curr){
                    s1[i] = '1';
                }
                i++;
            }
        }
        int b = stoi(s1);
        return a - b;
    }
};

//9 -> 0
//!1 - > 1