class Solution {
public:
    int minDeletion(string s, int k) {
        int n = s.size();
        vector<int> check(26,0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(check[s[i] - 'a'] == 0) cnt++;
            check[s[i] - 'a']++;
        }
        if(cnt <= k) return 0;
        int ans = 0;
        sort(check.begin(), check.end());
        for(int i = 0; i < 26; i++){
            if(check[i] > 0){
                ans += check[i];
                cnt--;
                if(cnt == k){
                    break;
                }
            }
        }
        return ans;
    }
};