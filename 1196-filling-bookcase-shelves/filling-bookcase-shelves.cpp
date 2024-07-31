// class Solution {
// public:
//     int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
//         int n = books.size();
//         vector<pair<int,int>> dp;
//         dp.push_back({0,0});
//         dp.push_back({books[0][0],books[0][1]});
//         int rowHeight = books[0][1];
//         for(int i = 1; i < n; i++){
//             if(dp[i].first + books[i][0] <= shelfWidth){
//                 dp.push_back({dp[i].first + books[i][0], max(dp[i].second,dp[i].second + books[i][1] - rowHeight)});
//                 rowHeight = max(rowHeight,books[i][1]);
//             }else{
//                 if(((dp[i-1].second + max(books[i-1][1],books[i][1])) < dp[i].second + books[i][1]) && (books[i-1][0] + books[i][0] <= shelfWidth)){
//                     dp[i].first = books[i-1][0];
//                     int fc = dp[i-1].second;
//                     dp[i].second = fc + books[i-1][1];
//                     rowHeight = max(books[i-1][1],books[i][1]);
//                     dp.push_back({books[i-1][0] + books[i][0],fc + max(books[i-1][1],books[i][1])});
//                 }else{
//                     rowHeight = books[i][1];
//                     dp.push_back({books[i][0],books[i][1] + dp[i].second});
//                 }
//             }
            
//         }
//         return dp[n].second;
//     }
// };

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        int tW;
        int mH;
        for(int i = 1; i <= n; i++){
            tW = 0;
            mH = 0;
            for(int j = i; j > 0; j--){
                tW += books[j-1][0];
                if(tW > shelfWidth){
                    break;
                }
                mH = max(mH, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + mH);
            }
        }
        return dp[n];
    }
};