class Solution {
public:
    const long long mod = 1000000007; 
    // int getAns(vector<vector<int>> &check, int i, int j, string &target, vector<vector<int>> &dp){
    //     if(j == target.size()){
    //         return 1;
    //     }
    //     if(i == check.size()){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     long long nt = getAns(check, i+1,j, target, dp);
    //     long long tk = 0;
    //     if(check[i][target[j] - 'a'] > 0) tk = ((long long) check[i][target[j] - 'a'] * getAns(check,i+1,j+1,target,dp))%mod;
    //     return dp[i][j] = (nt + tk) % mod;
    // }

    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int t = target.size();
        vector<vector<int>> check(n,vector<int>(26,0));
        vector<vector<int>> dp(n+1,vector<int>(t+1,0));
        vector<int> prev(t+1,0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < words.size(); j++){
                check[i][words[j][i] - 'a']++;
            }
        }
        // for(int i = 0; i <= n; i++){
        //     prev[i] = 1;
        // }
        
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
        // return getAns(check,0,0,target,dp);
    }
};

// i -> word.lenght;
// j -> target.length;

// 0
// a 1
// b 1
// c 1

// 1
// a 2
// b 1

// 2 
// b 1
// c 2

// 3 
// a 2
// b 1


// 0 1 3 (2)
// 0 2 3 (2)
// 1 2 3 (4)

