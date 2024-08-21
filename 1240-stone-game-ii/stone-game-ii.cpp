class Solution {
public:
    int getAns(int alice, vector<int> piles, vector<vector<vector<int>>> &dp, int m, int idx, int n){
        if(idx == piles.size()){
            return 0;
        }
        if(dp[alice][idx][m] != -1){
            return dp[alice][idx][m];
        }
        int sum = 0;
        int stones = (alice == 1 ? 0 : INT_MAX);
        for(int x = 1; x <= 2*m; x++){
            if(idx + x > n){
                break;
            }
            sum += piles[idx + x - 1];
            if(alice == 1){
                stones = max(stones, sum + getAns(0,piles,dp,max(x,m), idx + x, n));
            }else{
                stones = min(stones, getAns(1,piles,dp,max(x,m), idx + x, n));
            }
        }
        return dp[alice][idx][m] = stones;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        if(n == 1){
            return piles[0];
        }
        vector<vector<vector<int>>> dp(2,vector(n+1, vector<int>(n+1, -1)));
        return getAns(1,piles,dp,1,0,n);    
    }
};