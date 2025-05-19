class Solution {
public:
    int n;
    int mod = 1e9 + 7;
    int getAns(unordered_map<int,vector<int>> &mp, int hat, int person, vector<vector<int>> &dp){
        if(person == ((1 << n) - 1)){
            return 1;
        }
        if(hat == 41){
            return 0;
        }
        if(dp[hat][person] != -1) return dp[hat][person];
        int ans = 0;
        for(auto &p : mp[hat]){
            if((person & (1 << (p))) == 0){
                ans = (ans + getAns(mp, hat + 1, person + (1 << p), dp)) % mod;
            } 
        }
        ans = (ans + getAns(mp, hat + 1, person, dp)) % mod;
        return dp[hat][person] = ans;
    }


    int numberWays(vector<vector<int>>& hats) {
        unordered_map<int,vector<int>> mp;
        n = hats.size();
        for(int i = 0; i < n; i++){
            for(auto &h : hats[i]){
                mp[h].push_back(i);
            }
        }
        vector<vector<int>> dp(41, vector<int>((1 << n), -1));
        return getAns(mp, 0, 0, dp);
    }
};