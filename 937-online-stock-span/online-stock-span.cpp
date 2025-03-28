class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i;
    StockSpanner() {
        i = 1;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int gap;
        if(st.empty()){
            gap = i;
        }else{
            gap = i - st.top().second;
        }
        st.push({price, i});
        i++;
        return gap;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */