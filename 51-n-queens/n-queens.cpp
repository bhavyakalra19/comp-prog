class Solution {
public:
    bool isValid(vector<string> &check, int a, int b, int &n){
        //check col
        for(int i = 0; i < a; i++) if(check[i][b] == 'Q') return false;
        
        //check diagnal1
        int i = a;
        int j = b;
        while(i >= 0 && j >= 0){
            if(check[i][j] == 'Q') return false;
            i--;
            j--;
        }
        //check diagnol2
        i = a;
        j = b;
        while(i >= 0 && j < n){
            if(check[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }


    void getAns(vector<string> &check, int idx, int &n, vector<vector<string>> &ans){
        if(idx == n){
            ans.push_back(check);
            return;
        }
        for(int i = 0; i < n; i++){
            if(isValid(check, idx, i, n)){
                check[idx][i] = 'Q';
                getAns(check, idx + 1, n, ans);
                check[idx][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s = "";
        for(int i = 0; i < n; i++) s += '.';
        vector<string> check(n,s);
        getAns(check, 0, n, ans);
        return ans;
    }
};