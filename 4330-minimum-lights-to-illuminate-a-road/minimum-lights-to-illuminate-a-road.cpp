class Solution {
public:
    int minLights(vector<int>& lights) {
        stack<int> st;
        int next_max = -1;
        int n = lights.size();
        for(int i = 0; i < n; i++){
            if(lights[i] == 0 && next_max < i){
                st.push(i);
            }else if(lights[i] != 0){
                int prev = max(0, i - lights[i]);
                next_max = max(next_max, i + lights[i]);
                while(!st.empty() && st.top() >= prev){
                    st.pop();
                }
            }
        }
        int ans = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(!st.empty() && st.top() == top - 1){
                st.pop();
                if(!st.empty() && st.top() == top - 2){
                    st.pop();
                }
            }
            ans++;
        }
        return ans;
    }
};

// take -> next_max
// take -> stack
