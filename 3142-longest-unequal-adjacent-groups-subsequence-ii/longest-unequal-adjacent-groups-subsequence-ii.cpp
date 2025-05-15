class Solution {
public:
    bool checkStrings(string w1, string w2){
        int n = w1.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(w1[i] != w2[i]){
                cnt++;
                if(cnt == 2) return false;
            }
        }
        return true;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n,1);
        vector<int> check(n,0);
        int mx = 0;
        int mxIdx = 0;
        for(int i = 1; i < n; i++){
            int curr = 1;
            int currIdx = i;
            for(int j = 0; j < i; j++){
                if(groups[i] != groups[j] && dp[j] + 1 > curr && words[i].size() == words[j].size() && checkStrings(words[i], words[j])){
                    curr = dp[j] + 1;
                    currIdx = j;
                }
            }
            check[i] = currIdx;
            dp[i] = curr;
            if(curr > mx){
                mx = curr;
                mxIdx = i; 
            }
        }
        vector<string> ans;
        while(mxIdx != check[mxIdx]){
            ans.push_back(words[mxIdx]);
            mxIdx = check[mxIdx];
        }
        ans.push_back(words[mxIdx]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};