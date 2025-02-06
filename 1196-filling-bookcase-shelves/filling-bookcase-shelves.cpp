class Solution {
public:
    int n;
    int getAns(vector<vector<int>> &books, int idx, int &sw, vector<int> &dp){
        if(idx == n) return 0;
        int mh = 0;
        int mw = 0;
        int mn = INT_MAX;
        if(dp[idx] != -1) return dp[idx];
        for(int i = idx; i < n; i++){
            if(mw + books[i][0] <= sw){
                mh = max(mh, books[i][1]);
                mw += books[i][0];
                mn = min(mn, mh + getAns(books, i+1, sw, dp));
            }else{
                break;
            }
        }
        return dp[idx] = mn; 
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        vector<int> dp(n,-1);
        return getAns(books, 0, shelfWidth, dp); 
    }
};