class Solution {
public:

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1, 0);
        for(int idx = n-1; idx >= 0; idx--){
            int mh = 0;
            int mw = 0;
            int mn = INT_MAX;
            for(int i = idx; i < n; i++){
                if(mw + books[i][0] <= shelfWidth){
                    mh = max(mh, books[i][1]);
                    mw += books[i][0];
                    mn = min(mn, mh + dp[i+1]);
                }else{
                    break;
                }
            }
            dp[idx] = mn;
        }
        return dp[0]; 
    }
};