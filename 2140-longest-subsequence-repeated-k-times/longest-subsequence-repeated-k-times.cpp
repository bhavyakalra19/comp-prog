class Solution {
public:
    void dfs(vector<int> &check, vector<string> &source, int &mx, string curr){
        if(curr.size() == mx){
            source.push_back(curr);
            return;
        }
        for(int i = 25; i >= 0; i--){
            if(check[i] > 0){
                check[i] -= 1;
                char a = i + 'a';
                dfs(check, source, mx, curr + a);
                check[i] += 1;
            }
        }
    }

    bool getAns(string s, string check, int &n, int &m, int k){
        int j = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == check[j]){
                j++;
                if(j == m){
                    j = 0;
                    cnt++;
                    if(cnt == k) return true;
                }
            }
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> check(26, 0);
        for(auto &a : s){
            check[a - 'a']++;
        }
        vector<char> avail;
        int mxCount = 0;
        for(int i = 0; i < 26; i++){
            check[i] = check[i] / k;
            mxCount += check[i];
        }
        int n = s.size();
        for(int i = min(7, mxCount); i >= 1; i--){
            vector<string> allString;
            dfs(check, allString, i, "");
            for(auto a : allString){
                if(getAns(s, a, n, i, k)) return a;
            }
        }
        return "";
    }
};
