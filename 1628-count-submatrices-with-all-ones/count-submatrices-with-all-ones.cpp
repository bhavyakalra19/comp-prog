class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<int> h(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) h[j] = mat[i][j] ? h[j] + 1 : 0;
            vector<int> sum(m, 0);
            stack<int> st;
            for(int j = 0; j < m; j++){
                while(!st.empty() && h[st.top()] >= h[j]){
                    st.pop();
                }
                if(st.empty()){
                    sum[j] = h[j] * (j + 1);
                }else{
                    sum[j] = sum[st.top()] + h[j] * (j - st.top());
                }
                st.push(j);
                ans += sum[j];
            }
        }
        return ans;
    }
};