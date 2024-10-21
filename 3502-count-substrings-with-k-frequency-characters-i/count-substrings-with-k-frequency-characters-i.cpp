class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        vector<int> check(26,0);
        int ans = 0;
        int count = 0;
        int n = s.size();
        if(k == 1){
            return n*(n+1)/2;
        }
        int j = 0;
        for(int i = 0; i < n; i++){
            int curr = s[i] - 'a';
            check[curr]++;
            if(check[curr] == k){
                count++;
            }
            while(count > 0){
                ans += n - i;
                int curr = s[j] - 'a';
                if(check[curr] == k){
                    count--;
                }
                check[curr]--;
                j++;
            }
        }
        return ans;
    }
};