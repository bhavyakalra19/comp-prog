class NumMatrix {
public:
    vector<vector<int>> check;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        check.resize(n,vector<int>(m));
        for(int i = 0; i < n; i++){
            int sm = 0;
            for(int j = 0; j < m; j++){
                sm += matrix[i][j];
                check[i][j] = sm;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++){
            if(col1 != 0){
                sum -= check[i][col1-1];
            }
            sum += check[i][col2];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */