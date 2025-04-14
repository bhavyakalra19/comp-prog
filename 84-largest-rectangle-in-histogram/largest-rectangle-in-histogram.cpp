class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int top = st.top();
                st.pop();
                int lf = st.empty() ? top: top - st.top() - 1;
                int rt = i - top;
                ans = max(ans, (lf + rt) * heights[top]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();
            int lf = st.empty() ? top: top - st.top() - 1;
            int rt = n - top;
            ans = max(ans, (lf + rt) * heights[top]);
        }
        return ans;
    }
};