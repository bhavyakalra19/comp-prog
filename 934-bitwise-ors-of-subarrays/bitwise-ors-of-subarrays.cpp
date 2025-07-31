class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> st;
        int n = arr.size();
        unordered_set<int> prev;
        prev.insert(arr[n-1]);
        for(int i = n-2; i >= 0; i--){
            unordered_set<int> curr;
            for(auto a : prev){
                st.insert(a);
                curr.insert(a | arr[i]);
            }
            curr.insert(arr[i]);
            prev = curr;
        }
        for(auto &a : prev){
            st.insert(a);
        }
        return st.size();
    }
};