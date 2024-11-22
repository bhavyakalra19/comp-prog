class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<string,int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++){
            string ec = "";
            string oc = "";
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    oc += j;
                }else{
                    ec += j;
                }
            }
            if(ec.size() < oc.size()){
                mp[ec] += 1;
                ans = max(ans,mp[ec]);
            }else if(ec.size() == oc.size()){
                mp[ec] += 1;
                mp[oc] += 1;
                ans = max(ans,max(mp[ec],mp[oc]));
            }else{
                mp[oc] += 1;
                ans = max(ans,mp[oc]);
            }
        }
        return ans;
    }
};