class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> prefix(n, -1);
        vector<int> suffix(n, -1);
        if(n == 1) return true;
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(s[i] == t[j]){
                prefix[i] = j;
                i++;
                j++;
                if(i == n-1 && j < m) return true;
            }else{
                j++;
            }
        }

        i = n-1;
        j = m-1;
        while(j >= 0 && i >= 0){
            if(s[i] == t[j]){
                suffix[i] = j;
                i--;
                j--;
                if(i == 0 && j >= 0) return true;
            }else{
                j--;
            }
        }

        for(int i = 1; i < n-1; i++){
            int a = prefix[i-1];
            int b = suffix[i+1];
            if(a != -1 && b != -1 && b - a > 1) return true;
        }

        return false;
    }
};