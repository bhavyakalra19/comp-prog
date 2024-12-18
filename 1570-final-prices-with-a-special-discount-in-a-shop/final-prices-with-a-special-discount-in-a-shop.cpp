class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && prices[i] < st.top()){
                st.pop();
            }
            int temp = prices[i];
            if(!st.empty()){
                prices[i] -= st.top();
            }
            st.push(temp);
        }
        return prices;
    }
};
