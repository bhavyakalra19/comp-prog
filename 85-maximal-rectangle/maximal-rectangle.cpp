class Solution {
public:
    int getAns(vector<int> &nums, int n){
        stack<int> st;
        int ans = 0;
        int i = 0;
        while(i < n){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                int top = st.top();
                st.pop();
                int gap = i;
                if(!st.empty()){
                    gap = gap - st.top() - 1;
                }
                ans = max(ans, gap * nums[top]);
            }
            st.push(i);
            i++;
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();
            int gap = n;
            if(!st.empty()){
                gap = gap - st.top() - 1;
            }
            ans = max(ans, gap * nums[top]);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> prev(col,0);
        for(int i = 0; i < row; i++){
            vector<int> curr(col,0);
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    curr[j] = 1;
                    curr[j] += prev[j];
                } 
            }
            ans = max(ans, getAns(curr, col));
            prev = curr;
        }
        return ans;
    }
};