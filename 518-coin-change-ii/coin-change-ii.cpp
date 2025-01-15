class Solution {
public:

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> prev(amount+1, 0);
        prev[0] = 1;
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                prev[i] = 1;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= amount; j++){
                int a = 0;
                int b = prev[j];
                if(coins[i] <= j){
                    a = prev[j-coins[i]];
                }
                prev[j] = (long long)a + (long long)b;
            }
        }
        return prev[amount];
    }
};