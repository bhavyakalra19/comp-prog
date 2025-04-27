class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> prev(2, 0);
        for(int idx = n-1; idx >= 0; idx--){
            vector<int> curr(2, 0);
            for(int buy = 0; buy <= 1; buy++){
                if(buy == 1){
                    curr[buy] = max(prev[buy], prev[0] - prices[idx] - fee);
                }else{
                    curr[buy] = max(prev[buy], prices[idx] + prev[1]);
                }
            }
            prev = curr;
        }
        return prev[1];
    }
};