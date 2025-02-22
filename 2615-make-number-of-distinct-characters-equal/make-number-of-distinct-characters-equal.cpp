class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<int> check1(26, 0);
        vector<int> check2(26, 0);
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < max(n1,n2); i++){
            if(i < n1){
                int a = word1[i] - 'a';
                check1[a]++;
                if(check1[a] == 1) cnt1++;
            }
            if(i < n2){
                int a = word2[i] - 'a';
                check2[a]++;
                if(check2[a] == 1) cnt2++;
            }
        }
        if(abs(cnt1 - cnt2) > 2) return false;
        for(int i = 0; i < 26; i++){
            if(check1[i] == 0) continue;
            for(int j = 0; j < 26; j++){
                if(check2[j] == 0) continue;
                if(i == j){
                    if(cnt1 == cnt2) return true;
                    continue;
                }
                int a1 = cnt1;
                int a2 = cnt2;
                if(check1[i] == 1) a1--;
                if(check2[j] == 1) a2--;
                if(check1[j] == 0) a1++;
                if(check2[i] == 0) a2++;
                if(a1 == a2) return true;
            }
        }
        return false;
    }
};
