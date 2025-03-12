class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        vector<int> check1(26,0);
        vector<int> check2(26,0);
        int cnt1 = 0;
        int cnt2 = 0;
        for(auto &a : s1){
            int c = a - 'a';
            if(check1[c] == 0) cnt1++;
            check1[c]++;
        }
        for(int i = 0; i < n; i++){
            int a = s2[i] - 'a';
            check2[a]++;
            if(check2[a] == check1[a]) cnt2++;
        }
        if(cnt1 == cnt2) return true;

        for(int i = n; i < m; i++){
            int a = s2[i] - 'a';
            check2[a]++;
            if(check2[a] == check1[a]) cnt2++;

            a = s2[i - n] - 'a';
            if(check2[a] == check1[a]) cnt2--;
            check2[a]--;
            if(cnt2 == cnt1) return true;
        }
        return false;
    }
};