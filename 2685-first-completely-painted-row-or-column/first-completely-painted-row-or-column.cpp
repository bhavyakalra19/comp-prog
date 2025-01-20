class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int,pair<int,int>> check;
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                check[mat[i][j]] = make_pair(i,j);
            }
        }
        for(int cnt = 0; cnt < arr.size(); cnt++){
            int i = check[arr[cnt]].first;
            int j = check[arr[cnt]].second;
            row[i]++;
            col[j]++;
            if(row[i] == m || col[j] == n){
                return cnt;
            }
        }
        return arr.size() - 1;
    }
};