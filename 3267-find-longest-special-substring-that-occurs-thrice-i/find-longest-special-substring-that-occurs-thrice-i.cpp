class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string, int> mp;
        string prev = "";
        prev += s[0];
        for(int i = 1; i < n; i++){
            if(prev[0] != s[i]){
                mp[prev] += 1;
                prev = s[i];
            }else{
                prev += s[i];
            }
        }
        mp[prev] += 1;
        int ans = -1;
        for(auto m : mp){
            string str = m.first;
            int cnt = m.second;
            if(cnt > 2){
                ans = max(ans, (int) str.size());
            }else if(str.size() > 2){
                if(cnt == 2){
                    ans = max(ans, (int)str.size() - 1);
                }else{
                    ans = max(ans, (int)str.size() - 2);
                }
                string sub = str.substr(1);
                if(mp.find(sub) != mp.end()){
                    ans = max(ans, (int) sub.size());
                }
            }else if(str.size() == 2 && mp.find(str.substr(1)) != mp.end()){
                ans = max(ans,1);
            }
        }
        return ans;
    }
};