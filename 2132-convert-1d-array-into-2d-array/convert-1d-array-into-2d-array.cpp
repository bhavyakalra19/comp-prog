class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n));
        if(original.size() > m*n || m*n > original.size()){
            vector<vector<int>> a;
            return a;
        }
        for(int i = 0; i < original.size(); i++){
            ans[i/n][i%n] = original[i];
        }
        return ans;
    }
};