class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int n = g.size();
        int m = s.size();
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            while(j < m && s[j] < g[i]){
                j++;
            }
            if(j < m){
                i++;
                j++;
            }
        }
        return i;
    }
};