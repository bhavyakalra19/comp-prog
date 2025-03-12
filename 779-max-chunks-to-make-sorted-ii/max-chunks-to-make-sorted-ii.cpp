class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            if(st.empty() || arr[i] <= st.top()) st.push(arr[i]);
        }
        int ans = 0;
        int mx = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] == st.top()) st.pop();
            mx = max(mx, arr[i]);
            if(st.empty() || mx <= st.top()){
                ans++;
            }
        }
        return ans;
    }
};