class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            if(st.empty() || arr[i] <= st.top()){
                st.push(arr[i]);
            }
        }
        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(arr[i],mx);
            if(st.top() == arr[i]){
                st.pop();
            }
            if(st.empty() || st.top() >= mx){
                ans += 1;
            }
        }
        return ans;
    }
};