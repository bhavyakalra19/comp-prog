class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> check(3,0);
        int cnt = 0;
        int ans = n;
        if(k == 0) return 0;
        for(int i = 0; i < n; i++){
            int a = s[i] - 'a';
            check[a]++;
        }
        if((3 * k) > n) return -1;
        for(int i = 0; i < 3; i++){
            if(check[i] < k) return -1;
        }
        check[0] = 0;
        check[1] = 0;
        check[2] = 0;
        int j = 0;
        for(int i = 0; i < 2 * n; i++){
            int a = s[i % n] - 'a';
            check[a] += 1;
            if(check[a] == k) cnt++;
            if(j == 0 && cnt == 3){
                ans = min(ans, i - j + 1);
            }
            while(cnt == 3){
                if(i >= n-1 && j < n) ans = min(ans, i - j + 1);
                a = s[j % n] - 'a';
                if(check[a] == k){
                    break;
                }
                check[a]--;
                j++;
            }
            
        }
        return ans;
    }
};