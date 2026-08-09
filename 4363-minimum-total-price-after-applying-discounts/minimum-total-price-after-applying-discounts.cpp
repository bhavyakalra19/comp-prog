class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());
        double ans = 0;
        int j = 0;
        int n = prices.size();
        int m = discounts.size();
        for(int i = 0; i < n; i++){
            if(j < m){
                ans += ((double) prices[i] * (100 - discounts[j])) / 100;
                j++;
            }else{
                ans += prices[i];
            }
        }
        return ans;
    }
};