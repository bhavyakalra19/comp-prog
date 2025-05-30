class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            int a = 0;
            int b = n-1;
            while(a < b){
                swap(matrix[a][i], matrix[b][i]);
                a++;
                b--;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};