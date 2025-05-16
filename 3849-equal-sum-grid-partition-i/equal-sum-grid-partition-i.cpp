class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid1) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<long long> rowSum(n,0);
        vector<long long> colSum(m, 0);
        long long sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum += grid1[i][j];
                colSum[j] += grid1[i][j];
            }
            rowSum[i] = sum;
        }
        for(int i = 1; i < m; i++){
            colSum[i] += colSum[i-1];
        }
        if(rowSum[n-1] % 2 == 0){
            long long a = rowSum[n-1] / 2;
            for(int i = 0; i < n-1; i++){
                if(a == rowSum[i]){
                    return true;
                }
            }
        }
        if(colSum[m-1] % 2 == 0){
            long long a = colSum[m-1] / 2;
            for(int i = 0; i < m-1; i++){
                if(a == colSum[i]){
                    return true;
                }
            }
        }
        return false;
    }
};