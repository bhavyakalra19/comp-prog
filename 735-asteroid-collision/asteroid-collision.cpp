class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(asteroids[i] < 0){
                while(!st.empty() && -1 * asteroids[i] > st.top()){
                    st.pop();
                }
                
                if(!st.empty() && asteroids[i] == -1 * st.top()){
                    st.pop();
                    continue;
                }
                if(st.empty()) ans.push_back(asteroids[i]);
            }else{
                st.push(asteroids[i]);
            }
        }
        vector<int> check;
        while(!st.empty()){
            check.push_back(st.top());
            st.pop();
        }
        cout << check.size() << endl;
        reverse(check.begin(), check.end());
        for(auto a : check) ans.push_back(a);
        return ans;
    }
};