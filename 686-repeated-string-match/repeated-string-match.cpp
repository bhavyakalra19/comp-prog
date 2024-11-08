class Solution {
public:
    vector<int> getKmp(string str){
        vector<int> check;
        int n = str.size();
        int j = 0;
        check.push_back(0);
        for(int i = 1; i < n; i++){
            while(1){
                if(str[j] == str[i]){
                    j++;
                    check.push_back(j);
                    break;
                }else{
                    if(j == 0){
                        check.push_back(0);
                        break;
                    }
                    j = check[j-1];
                }
            }
        }
        return check;
    }

    int repeatedStringMatch(string s1, string s2) {
        int m = s2.size();
        int ans = 1;
        vector<int> check;
        check = getKmp(s2);
        string temp = s1;
        while(s1.size() < m){
            ans += 1;
            s1 += temp;
        }
        int n = s1.size();
        int j = 0;
        for(int i = 0; i < n; i++){
            while(1){
                if(s1[i] == s2[j]){
                    j++;
                    break;
                }else{
                    if(j == 0){
                        break;
                    }
                    j = check[j-1];
                }
            }
            if(j == m){
                return ans;
            }
        }
        if(j == 0){
            return -1;
        }
        ans += 1;
        s1 += temp;
        for(int i = n; i < s1.size(); i++){
            while(1){
                if(s1[i] == s2[j]){
                    j++;
                    break;
                }else{
                    if(j == 0){
                        break;
                    }
                    j = check[j-1];
                }
            }
            if(j == m){
                return ans;
            }
        }
        return -1;
    }
};