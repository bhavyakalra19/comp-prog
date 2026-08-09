class Solution {
public:
    int handle1DRow(vector<vector<int>>& mat, int m) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            if (mat[0][j] == 1) count++;
        }
        return (count >= 2) ? 1 : 0;
    }

    int handle1DCol(vector<vector<int>>& mat, int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 1) count++;
        }
        return (count >= 2) ? 1 : 0;
    }

    void calculateLeft(vector<vector<int>> &mat, int &n, int &m, vector<int> &left){
        vector<vector<int>> check(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            check[i][0] = mat[i][0];
            if(mat[i][0]) left[0] = 1;
        }
        for(int j = 0; j < m; j++){
            check[0][j] = mat[0][j];
        }
        for(int j = 1; j < m-1; j++){
            left[j] = check[0][j];
            for(int i = 1; i < n; i++){
                if(mat[i][j] == 0){
                    check[i][j] = 0;
                }else{
                    check[i][j] = 1 + min(check[i-1][j-1], min(check[i-1][j], check[i][j-1]));
                }
                left[j] = max(check[i][j], left[j]);
            }
        }
    }

    int getVerticleMax(vector<vector<int>> &mat, int &n, int &m, vector<int> &left){
        int mx = 0;
        vector<vector<int>> check(n, vector<int>(m, 0));
        for(int i = n-1; i >= 0; i--){
            check[i][m-1] = mat[i][m-1];
            if(check[i][m-1]) mx = 1; 
        }
        for(int j = 0; j < m; j++){
            check[0][j] = mat[0][j];
        }
        int ans = min(left[m-2], mx);
        for(int j = m-2; j > 0; j--){
            for(int i = 1; i < n; i++){
                if(mat[i][j] == 0){
                    check[i][j] = 0;
                }else{
                    check[i][j] = 1 + min(check[i-1][j], min(check[i][j+1], check[i-1][j+1]));
                }
                mx = max(mx, check[i][j]);
            }
            ans = max(ans, min(left[j-1], mx));
        }
        return ans * ans;
    }

    void calculateTop(vector<vector<int>> &mat, int &n, int &m, vector<int> &top){
        vector<vector<int>> check(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++){
            check[0][j] = mat[0][j];
            if(mat[0][j]) top[0] = 1;
        }
        for(int i = 0; i < n; i++){
            check[i][0] = mat[i][0];
        }
        for(int i = 1; i < n - 1; i++){
            top[i] = check[i][0];
            for(int j = 1; j < m; j++){
                if(mat[i][j] == 0){
                    check[i][j] = 0;
                }else{
                    check[i][j] = 1 + min(check[i-1][j-1], min(check[i-1][j], check[i][j-1]));
                }
                top[i] = max(check[i][j], top[i]);
            }
        }
    }

    int getHorizontalMax(vector<vector<int>> &mat, int &n, int &m, vector<int> &top){
        int mx = 0;
        vector<vector<int>> check(n, vector<int>(m, 0));
        for(int j = m - 1; j >= 0; j--){
            check[n-1][j] = mat[n-1][j];
            if(check[n-1][j]) mx = 1; 
        }
        for(int i = 0; i < n; i++){
            check[i][0] = mat[i][0];
        }
        int ans = min(top[n-2], mx);
        for(int i = n - 2; i > 0; i--){
            for(int j = 1; j < m; j++){
                if(mat[i][j] == 0){
                    check[i][j] = 0;
                }else{
                    check[i][j] = 1 + min(check[i+1][j-1], min(check[i+1][j], check[i][j-1]));
                }
                mx = max(mx, check[i][j]);
            }
            ans = max(ans, min(top[i-1], mx));
        }
        return ans * ans;
    }

    int maxArea(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return 0;

        int n = mat.size();
        int m = mat[0].size();

        if (n == 1) return handle1DRow(mat, m);
        if (m == 1) return handle1DCol(mat, n);

        vector<int> left(m, 0);
        calculateLeft(mat, n, m, left);
        for(int j = 0; j < m; j++){
            if(j > 0) left[j] = max(left[j], left[j-1]);
        }

        vector<int> top(n, 0);
        calculateTop(mat, n, m, top);
        for(int i = 0; i < n; i++){
            if(i > 0) top[i] = max(top[i], top[i-1]);
        }

        return max(getVerticleMax(mat, n, m, left), getHorizontalMax(mat, n, m, top));
    }
};