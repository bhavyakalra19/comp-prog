class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        vector<int> check(26,0);
        for(int i = 0; i < n; i++){
            int a = s[i] - 'A';
            check[a]++;
        }
        int mx = n/4;
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(check[i] > mx){
                check[i] -= mx;
                cnt++;
            }else{
                check[i] = 0;
            }
        }
        if(cnt == 0) return 0;
        int curr = 0;
        int i = 0;
        int ans = INT_MAX;
        vector<int> next(26,0);
        int j = 0;
        while(i < n){
            while(i < n && curr < cnt){
                int a = s[i] - 'A';
                next[a]++;
                if(next[a] == check[a]){
                    curr++;
                }
                i++;
            }
            while(j < i && curr == cnt){
                int a = s[j] - 'A';
                if(next[a] == check[a]){
                    curr--;
                    ans = min(ans, i - j);
                }
                next[a]--;
                j++;
            }
        }
        return ans;
    }
};