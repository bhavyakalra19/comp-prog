class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        vector<int> check(26,0);
        priority_queue<char> pq;
        for(auto a : s){
            if(check[a - 'a'] == 0){
                pq.push(a);
            }
            check[a - 'a']++;
        }
        char a = '\0';
        string ans = "";
        while(!pq.empty()){
            bool ch = false;
            if(pq.top() == a){
                pq.pop();
                ch = true;
            }
            if(pq.empty()){
                break;
            }
            auto it = pq.top();
            pq.pop();
            for(int i = 0; i < repeatLimit && check[it - 'a']; i++){
                ans += it;
                check[it - 'a']--;
                if(ch){
                    break;
                }
            }
            if(ch){
                pq.push(a);
            }
            a = it;
            if(check[it - 'a'] > 0){
                pq.push(it);
            }
        }
        return ans;
    }
};