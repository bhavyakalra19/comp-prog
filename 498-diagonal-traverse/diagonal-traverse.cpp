class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int a = i;
            int b = 0;
            vector<int> curr;
            while(a >= 0 && b < m){
                curr.push_back(mat[a][b]);
                a--;
                b++;
            }
            if(i % 2){
                reverse(curr.begin(), curr.end());
            }
            for(auto a : curr){
                ans.push_back(a);
            }
        }
        for(int j = 1; j < m; j++){
            int a = n-1;
            int b = j;
            vector<int> curr;
            while(b < m && a >= 0){
                curr.push_back(mat[a][b]);
                a--;
                b++;
            }
            if(((n % 2) && (j % 2)) || ((n % 2 == 0) && (j % 2 == 0))){
                reverse(curr.begin(), curr.end());
            }
            for(auto a : curr){
                ans.push_back(a);
            }
        }
        return ans;
    }
};
