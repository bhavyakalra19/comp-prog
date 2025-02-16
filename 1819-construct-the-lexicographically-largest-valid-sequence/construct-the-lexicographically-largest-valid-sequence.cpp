class Solution {
public:
    string ans = "";
    void getAns(vector<bool> &check, int &len, string str, int cnt, int idx, int &n){
        if(cnt == len || ans != ""){
            if(ans == "") ans = str;
            return;
        }
        while(idx < len && str[idx] != '0'){
            idx++;
        }
        if(idx == n) return;
        for(int i = n; i >= 1; i--){
            if(check[i] != false){
                if(i == 1){
                    str[idx] = (1 + '0');
                    check[i] = false;
                    getAns(check, len, str, cnt + 1, idx + 1, n);
                    str[idx] = '0';
                    check[i] = true;
                }else if((idx + i < len) && str[idx + i] == '0'){
                    str[idx] = (i + '0');
                    str[idx + i] = (i + '0');
                    check[i] = false;
                    getAns(check, len, str, cnt + 2, idx + 1, n);
                    str[idx] = '0';
                    str[idx + i] = '0';
                    check[i] = true;
                }
            }
        }
    }

    vector<int> constructDistancedSequence(int n) {
        vector<bool> check(n+1,true);
        int len = n*2 - 1;
        string s = "";
        for(int i = 0; i < len; i++){
            s += '0';
        }
        getAns(check, len, s, 0, 0, n);
        vector<int> an;
        for(auto &a : ans){
            an.push_back(a - '0');
        }
        return an;
    }
};