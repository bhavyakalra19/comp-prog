class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = bounds.size();
        for(int i = 0; i < n-1; i++){
            int cost = original[i+1] - original[i];
            if(bounds[i][0] + cost > bounds[i+1][1] || bounds[i][1] + cost < bounds[i+1][0]) return 0;
            bounds[i+1][0] = max(bounds[i+1][0], bounds[i][0] + cost);
            bounds[i+1][1] = min(bounds[i+1][1], bounds[i][1] + cost);
        }
        return bounds[n-1][1] - bounds[n-1][0] + 1;
    }
};