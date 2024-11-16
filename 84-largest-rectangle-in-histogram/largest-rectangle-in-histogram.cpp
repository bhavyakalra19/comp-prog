class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int i = 0;
        int mx = 0;
        while(i < n){
            if(st.empty() || heights[i] >= heights[st.top()]){
                st.push(i);
                i++;
            }else{
                int topIdx = st.top();
                st.pop();
                int width = st.empty() ? i : i - 1 - st.top();
                mx = max(mx, width * heights[topIdx]);
            }
        }
        while(!st.empty()){
            int topIdx = st.top();
            st.pop();
            int width = st.empty() ? i : i - 1 - st.top();
            mx = max(mx, width * heights[topIdx]);
        }
        return mx;
    }
};
