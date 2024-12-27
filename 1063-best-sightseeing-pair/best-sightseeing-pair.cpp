class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int mx = values[0];
        int ans = 0;
        for(int i = 1; i < values.size(); i++){
            mx -= 1;
            ans = max(ans, mx + values[i]);
            mx = max(mx, values[i]);
        }
        return ans;
    }
};