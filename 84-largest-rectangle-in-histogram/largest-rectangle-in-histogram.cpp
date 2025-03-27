class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                int top = st.top();
                st.pop();
                int gap;
                if(st.empty()){
                    gap = i;
                }else{
                    gap = (i - top) + (top - st.top() - 1);
                }
                ans = max(ans, heights[top] * gap);
            }
            st.push(i);
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();
            int gap;
            if(st.empty()){
                gap = n;
            }else{
                gap = n - st.top() - 1;
            }
            ans = max(ans, heights[top] * gap);
        }
        return ans;
    }
}; 