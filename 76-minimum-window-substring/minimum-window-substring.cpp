class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char,int> check1;
        int cnt1 = 0;
        for(auto &a : t){
            if(check1.find(a) == check1.end()) cnt1++;
            check1[a]++;
        }
        unordered_map<char,int> check2;
        int cnt2 = 0;
        int i = 0;
        int j = 0;
        string ans = s;
        bool check = false;
        while(i < n){
            while(i < n && cnt1 != cnt2){
                char c = s[i];
                i++;
                check2[c] += 1;
                if(check2[c] == check1[c]){
                    cnt2++;
                }
            }
            while(j < i && cnt2 == cnt1){
                char c = s[j];
                if(check2[c] == check1[c]){
                    if(ans.size() >= i - j){
                        check = true;
                        ans = s.substr(j,i-j);
                    }
                    cnt2--;
                }
                j++;
                check2[c]--;
            }
        }
        return check ? ans : "";
    }
};