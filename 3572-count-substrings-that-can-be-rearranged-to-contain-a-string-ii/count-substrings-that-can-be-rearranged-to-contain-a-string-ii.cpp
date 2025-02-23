class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<int> check1(26,0);
        vector<int> check2(26,0);
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < n2; i++){
            check2[word2[i] - 'a']++;
            if(check2[word2[i] - 'a'] == 1) cnt2++;
        }
        int i = 0;
        int j = 0;
        long long ans = 0;
        while(i < n1){
            while(i < n1 && cnt1 < cnt2){
                int a = word1[i] - 'a';
                check1[a]++;
                if(check1[a] == check2[a]) cnt1++;
                i++;
            }
            while(j < i && cnt1 == cnt2){
                ans += n1 - i + 1;
                int a = word1[j] - 'a';
                if(check2[a] != 0 && check1[a] == check2[a]) cnt1--;
                check1[a]--;
                j++;
            }
        }
        return ans;
    }
};