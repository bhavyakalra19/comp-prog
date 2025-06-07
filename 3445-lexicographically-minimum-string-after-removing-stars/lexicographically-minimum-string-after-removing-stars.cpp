class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        unordered_map<int, priority_queue<int>> mp;
        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                for(int i = 0; i < 26; i++){
                    if(!mp[i].empty()){
                        int t = mp[i].top();
                        mp[i].pop();
                        s[t] = '*';
                        break;
                    }
                }
            }else{
                int a = s[i] - 'a';
                mp[a].push(i);
            }
        }
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] != '*'){
                ans += s[i];
            }
        }
        return ans;
    }
};