class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        string cp = str;
        int n = str.size();
        int i = 0;
        while(i < n && str[i] == '9'){
            i++;
        }
        if(i != n){
            char a = str[i];
            for(int j = 0; j < n; j++){
                if(a == str[j]){
                    str[j] = '9';
                }
            }
        }
        int num1 = stoi(str);
        str = cp;
        i = 0;
        while(i < n && str[i] == '0'){
            i++;
        }
        if(i != n){
            char a = str[i];
            for(int j = 0; j < n; j++){
                if(a == str[j]){
                    str[j] = '0';
                }
            }
        }
        int num2 = stoi(str);
        return num1 - num2;
    }
};