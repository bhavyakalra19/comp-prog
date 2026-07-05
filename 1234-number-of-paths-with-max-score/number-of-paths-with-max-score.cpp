class Solution {
public:
    int n;
    int m;

    vector<vector<pair<int,int>>> check;
    int mod = 1e9 + 7;

    pair<int,int> getAns(vector<string> &board, int i, int j){
        if(i == n || j == m) return {-1, 0};
        if(i == n-1 && j == m-1) return {0, 1};
        if(board[i][j] == 'X') return {-1, 0};

        if(check[i][j].first != INT_MIN) return check[i][j];

        pair<int,int> a = getAns(board, i + 1, j);
        pair<int,int> b = getAns(board, i, j + 1);
        pair<int,int> c = getAns(board, i+1, j+1);

        int mx = max(a.first, max(b.first, c.first));
        if(mx == -1) return check[i][j] = {-1, 0};
        int ways = 0;
        if(a.first == mx) ways = (ways + a.second) % mod;
        if(b.first == mx) ways = (ways + b.second) % mod;
        if(c.first == mx) ways = (ways + c.second) % mod;

        return check[i][j] = {mx + (int)(board[i][j] - '0'), ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        m = board[0].size();
        check.resize(n, vector<pair<int,int>>(m, {INT_MIN, 0}));
        board[0][0] = '0';
        getAns(board, 0, 0);
        if(check[0][0].first == -1) check[0][0].first = 0;
        return {check[0][0].first, check[0][0].second};
    }
};