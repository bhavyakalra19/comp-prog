class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> prev(amount + 1, 0);
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                prev[i] = 1;
            }
        }
        for(int i = 1; i < n; i++){
            vector<long long> curr(amount + 1, 0);
            for(int j = 0; j <= amount; j++){
                int nt = prev[j];
                int tk = 0;
                if(coins[i] <= j){
                    tk = curr[j - coins[i]];
                }
                curr[j] = (long long)nt + (long long)tk;
            }
            prev = curr;
        }
        return prev[amount];
    }
};