class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,INT_MAX);
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                prev[i] = i / coins[0];
            }
        }
        prev[0] = 0;
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= amount; j++){
                int a = INT_MAX;
                int b = prev[j];
                if(coins[i] <= j){
                    a = prev[j - coins[i]];
                }
                if(a != INT_MAX){
                    a++;
                }
                prev[j] = min(a,b);
            }
        }
        // int a = getAns(coins,n-1,amount,dp);
        // return a == INT_MAX ? -1 : a;
        return prev[amount] != INT_MAX ? prev[amount] : -1;
    }
};

// f(coins, idx , amount)
// f(coins, idx - 1, amount)
// f(coins, idx,amount - coins[i])


// if(amount == 0){
//     return 0;
// }
// if(idx == 0){
//     if amount % coins[idx] == 0 return amount / coins[idx];
//     return INT_MAX;
// }
