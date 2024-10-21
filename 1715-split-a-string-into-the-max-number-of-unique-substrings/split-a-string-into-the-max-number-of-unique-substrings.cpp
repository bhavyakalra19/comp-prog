class Solution {
public:
    int ans;
    int n;
    void getAns(string s, int idx, unordered_map<string,bool> &mp, int num){
        if(idx >= n){
            ans = max(ans,num);
            return;
        }
        string curr = "";
        for(int i = idx; i < n; i++){
            curr += s[i];
            if(mp[curr] == false){
                mp[curr] = true;
                getAns(s,i+1,mp,num+1);
                mp[curr] = false;
            }
        }
    }

    int maxUniqueSplit(string s) {
        ans = 0;
        n = s.size();
        string curr = "";

        for(int i = 0; i < n; i++){
            unordered_map<string,bool> mp;
            string sub = s.substr(0,i+1);
            mp[sub] = true;
            getAns(s,i+1,mp,1);
        }
        return ans;
    }
};