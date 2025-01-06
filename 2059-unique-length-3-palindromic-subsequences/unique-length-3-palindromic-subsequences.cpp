class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<bool> mp(677,false);
        vector<int> right(26,0);
        vector<int> left(26,0);
        for(int i = 1; i < n; i++){
            right[s[i] - 'a']++;
        }
        left[s[0] - 'a']++;
        int ans = 0;
        for(int i = 1; i < n; i++){
            int a = s[i] - 'a';
            right[a]--;
            for(int j = 0; j < 26; j++){
                if(left[j] > 0 && right[j] > 0 && !mp[j * 26 + a]){
                    ans += 1;
                    mp[j * 26 + a] = true;
                }
            }
            left[a]++;
        }
        return ans;
    }
};