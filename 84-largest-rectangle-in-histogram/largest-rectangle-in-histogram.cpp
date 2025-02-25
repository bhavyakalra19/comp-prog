class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;
        int i = 0;
        while(i < n){
            if(st.empty() || heights[i] > heights[st.top()]){
                st.push(i);
                i++;
            }else{
                int topIdx = st.top();
                st.pop();
                int width = i - (st.empty() ? -1 : st.top()) - 1;
                ans = max(ans, width * heights[topIdx]);
            }
        }
        int prev = st.top();
        while(!st.empty()){
            int topIdx = st.top();
            st.pop();
            int width = prev - (st.empty() ? -1 : st.top());
            ans = max(ans, width * heights[topIdx]);
        }
        return ans;
    }
};