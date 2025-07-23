class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0;
        for(auto &a : s){
            if(x > y){
                if(a == 'a'){
                    st.push(a);
                }else if(a == 'b'){
                    if(!st.empty() && st.top() == 'a'){
                        st.pop();
                        ans += x;
                    }else{
                        st.push(a);
                    }
                }else{
                    int cnt = 0;
                    while(!st.empty()){
                        if(st.top() == 'a'){
                            cnt++;
                        }else if(cnt != 0){
                            ans += y;
                            cnt--;
                        }
                        st.pop();
                    }
                }
            }else{
                if(a == 'b'){
                    st.push(a);
                }else if(a == 'a'){
                    if(!st.empty() && st.top() == 'b'){
                        st.pop();
                        ans += y;
                    }else{
                        st.push(a);
                    }
                }else{
                    int cnt = 0;
                    while(!st.empty()){
                        if(st.top() == 'b'){
                            cnt++;
                        }else if(cnt != 0){
                            ans += x;
                            cnt--;
                        }
                        st.pop();
                    }
                }
            }
        }
        if(x > y){
            int cnt = 0;
            while(!st.empty()){
                if(st.top() == 'a'){
                    cnt++;
                }else if(cnt != 0){
                    ans += y;
                    cnt--;
                }
                st.pop();
            }
        }else{
            int cnt = 0;
            while(!st.empty()){
                if(st.top() == 'b'){
                    cnt++;
                }else if(cnt != 0){
                    ans += x;
                    cnt--;
                }
                st.pop();
            }
        }
        return ans;
    }
};
