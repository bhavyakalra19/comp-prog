class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n,1);
        vector<int> check(n,0);
        int mx = 0;
        int mxIdx = 0;
        for(int i = 1; i < n; i++){
            int curr = 1;
            int currIdx = i;
            for(int j = 0; j < i; j++){
                if(groups[i] != groups[j] && dp[j] + 1 > curr){
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