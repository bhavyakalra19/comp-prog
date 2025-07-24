class Solution {
public:
    int mod = 1e9 + 7;
    int possibleStringCount(string word, int k) {
        vector<int> arr;
        int n = word.size();
        int cnt = 0;
        long long total = 1;
        for(int i = 0; i < n; i++){
            if(i < n && word[i] == word[i+1]){
                cnt++;
            }else{
                arr.push_back(cnt + 1);
                total = (total * (cnt + 1)) % mod;
                cnt = 0;
            }
        }
        n = arr.size();
        if(n >= k) return total;
        vector<int> prev(k+1, 1);
        k--;
        for(int i = n-1; i >= 0; i--){
            vector<int> curr(k + 1, 0);
            for(int j = k-1; j >= 0; j--){
                prev[j] = (prev[j] + prev[j+1]) % mod; 
            }
            for(int j = n - i - 1; j <= k; j++){
                int ans = 0;
                curr[j] = (prev[j - min(arr[i],j)] - prev[j] + mod) % mod;
            }
            prev = curr;
        }
        int a = prev[k];
        return (total - a + mod) % mod;
    }
};
