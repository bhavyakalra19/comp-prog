class Solution {
public:
    bool getInc(string s, int i, int n){
        int j = i+1;
        while(i >= 0 && j < n){
            if(s[i] != s[j]){
                return 0;
            }
            i--;
            j++;
        }
        if(j == n && i >= 0){
            return 0;
        }
        return 1;
    }

    int getExc(string s, int i, int n){
        cout << i << endl;
        int j = i+1;
        i -= 1;
        while(i >= 0 && j < n){
            if(s[i] != s[j]){
                return 0;
            }
            i--;
            j++;
        }
        if(j == n && i >= 0){
            return 0;
        }
        return 1;
    }

    string shortestPalindrome(string s) {
        int n = s.size();
        if(n < 2){
            return s;
        }
        if(n == 2){
            if(s[0] == s[1]){
                return s;
            }else{
                string temp = s.substr(1);
                reverse(temp.begin(),temp.end());
                return temp + s;
            }
        }
        int mx = 0;
        int check = -1;
        for(int i = n/2 + 1; i >= 0; i--){
            if(getInc(s,i,n)){
                mx = i;
                check = 0;
                break;
            }
            if(i > 0 && getExc(s,i,n)){
                cout << "hello" << endl;
                mx = i;
                check = 1;
                break;
            }
        }
        if(check == 0){
            string temp = s.substr((mx + 1)*2);
            reverse(temp.begin(),temp.end());
            return temp + s;
        }
        if(check == 1){
            string temp = s.substr((mx * 2) + 1);
            reverse(temp.begin(),temp.end());
            return temp + s;
        }
        string temp = s.substr(1);
        reverse(temp.begin(),temp.end());
        return temp + s;
    }
};