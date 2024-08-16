class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int a = arrays[0][0];
        int b = arrays[0].back();
        int n = arrays.size();
        int md = 0;
        for(int i = 1; i < n; i++){
            int sm = arrays[i][0];
            int lg = arrays[i][arrays[i].size() - 1];
            md = max(md, abs(lg - a));
            md = max(md,abs(b - sm));
            a = min(a,sm);
            b = max(b,lg);
        }
        return md;
    }
};