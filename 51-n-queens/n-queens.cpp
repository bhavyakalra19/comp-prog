class Solution {
public:
    bool validate(vector<string> &check, int r, int c, int &n){
        //check upper row
        for(int i = 0; i < r; i++){
            if(check[i][c] == 'Q'){
                return false;
            }
        }
        //check left diagnol
        int i = r;
        int j = c;
        while(i >= 0 && j >= 0){
            if(check[i][j] == 'Q') return false;
            i--;
            j--;
        }
        //check right diagnol
        i = r;
        j = c;
        while(i >= 0 && j < n){
            if(check[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }

    void getAns(vector<string> &check, int idx, vector<vector<string>> &ans, int &n){
        if(idx == n){
            ans.push_back(check);
            return;
        }
        for(int i = 0; i < n; i++){
            if(validate(check, idx, i, n)){
                check[idx][i] = 'Q';
                getAns(check, idx + 1, ans, n);
                check[idx][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string st(n,'.');
        vector<string> check(n, st);
        vector<vector<string>> ans;
        getAns(check, 0, ans, n);
        return ans;
    }
};