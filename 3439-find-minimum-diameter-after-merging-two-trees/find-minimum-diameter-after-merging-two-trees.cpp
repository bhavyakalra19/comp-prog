class Solution {
public:
    int getMax(vector<vector<int>> &edges, int idx, int &diameter, int parent){
        int mx1 = 0;
        int mx2 = 0;
        for(auto a : edges[idx]){
            if(a != parent){
                int dep = getMax(edges,a,diameter,idx);
                if(dep > mx1){
                    mx2 = mx1;
                    mx1 = dep;
                }else if(dep > mx2){
                    mx2 = dep;
                }
            }
        }
        diameter = max(mx1 + mx2, diameter);
        return mx1 + 1;
    }



    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();
        vector<vector<int>> mp1(n+1);
        vector<vector<int>> mp2(m+1);
        for(auto a : edges1){
            mp1[a[0]].push_back(a[1]);
            mp1[a[1]].push_back(a[0]);
        }
        for(auto a : edges2){
            mp2[a[0]].push_back(a[1]);
            mp2[a[1]].push_back(a[0]);
        }
        int d1 = 0;
        getMax(mp1, 0, d1, -1);
        int d2 = 0;
        getMax(mp2, 0, d2, -1);
        return max(d1,max(d2, (d1 + 1)/2 + (d2 + 1)/2 + 1));
    }
};