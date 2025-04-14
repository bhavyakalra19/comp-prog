class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> left(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            }else{
                left[i] = st.top();
            }
            st.push(i);
        }
        stack<int> st1;
        vector<int> right(n);
        for(int i = n-1; i >= 0; i--){
            while(!st1.empty() && arr[st1.top()] >= arr[i]){
                st1.pop();
            }
            if(st1.empty()){
                right[i] = n;
            }else{
                right[i] = st1.top();
            }
            st1.push(i);
        }
        long long total = 0;
        for(int i = 0; i < n; i++){
            long long lf = i - left[i];
            long long rt = right[i] - i;
            long long comb = (lf * rt) % mod;
            total = (total + (arr[i] * comb)) % mod;
        }
        return total;
    }
};