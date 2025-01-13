class Solution {
public:
    bool compareStrings(string s1, string s2){
        if(s1.size() != (s2.size() + 1)){
            return false;
        }
        int i = 0;
        int j = 0;
        while(i < s1.size()){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(i == s1.size() && j == s2.size()){
            return true;
        }
        return false;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &s1, const string &s2){
            return s1.size() < s2.size();
        });
        int n = words.size();
        vector<int> dp(n,1);
        int mx = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(compareStrings(words[i], words[j]) && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
                mx = max(mx, dp[i]);
            }
        }
        return mx;
    }
};