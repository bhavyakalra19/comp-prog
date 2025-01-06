class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]){
            return 0;
        }
        vector<int> prev(m,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0){
                    prev[j] = 1;
                }else{
                    int a = 0;
                    int b = 0;
                    if(i - 1 >= 0 && !obstacleGrid[i-1][j]){
                        a = prev[j];
                    }
                    if(j - 1 >= 0 && !obstacleGrid[i][j-1]){
                        b = prev[j-1];
                    }
                    prev[j] = a + b;
                }
            }
        }
        return prev[m-1];
    }
};