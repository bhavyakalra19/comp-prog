class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        vector<int> check(26, 0);
        for(int i = 0; i < n; i++){
            check[word[i] - 'a']++;
        }
        int mn = INT_MAX;
        int mx = 0;
        vector<int> arr;
        for(int i = 0; i < 26; i++){
            if(check[i] != 0){
                mn = min(mn, check[i]);
                mx = max(mx, check[i]);
                arr.push_back(check[i]);
            }
        }
        int i = mn;
        int j = mn + k;
        if(j > mx) return 0;
        int ans = INT_MAX;
        while(j <= mx){
            int curr = 0;
            for(auto a : arr){
                if(a < i){
                    curr += a;
                }else if(a > j){
                    curr += a - j;
                }
            }
            i++;
            j++;
            ans = min(ans, curr);
        }
        return ans;
    }
};