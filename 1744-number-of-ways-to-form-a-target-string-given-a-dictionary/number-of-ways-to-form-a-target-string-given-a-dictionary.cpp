class Solution {
public:
    const long long mod = 1000000007;
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int t = target.size();
        vector<vector<int>> check(n,vector<int>(26,0));
        vector<int> prev(t+1,0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < words.size(); j++){
                check[i][words[j][i] - 'a']++;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            prev[t] = 1;
            vector<int> curr(t+1,0);
            for(int j = t - 1; j >= 0; j--){
                long long nt = prev[j];
                long long tk = 0;
                if(check[i][target[j] - 'a']) tk = ((long long)check[i][target[j] - 'a'] * prev[j+1])%mod;
                curr[j] = (nt + tk)%mod;
            }
            prev = curr;
        }
        return prev[0];
    }
};

