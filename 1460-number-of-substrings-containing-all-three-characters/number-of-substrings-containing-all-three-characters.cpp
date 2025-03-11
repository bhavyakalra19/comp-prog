class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> check(3,0);
        int i = 0;
        int j = 0;
        int cnt = 0;
        int ans = 0;
        while(i < n){
            while(i < n && cnt < 3){
                int a = s[i] - 'a';
                if(check[a] == 0) cnt++;
                check[a]++;
                i++;
            }
            while(cnt == 3){
                ans += n - i + 1;
                int a = s[j] - 'a';
                if(check[a] == 1) cnt--;
                check[a]--;
                j++;
            }
        }
        return ans;
    }
};