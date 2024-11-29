class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int mx = 0;
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            if(st.empty() || st.top() >= arr[i]){
                st.push(arr[i]);
            }
        }
        for(int i = 0; i < n; i++){
            mx = max(mx,arr[i]);
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