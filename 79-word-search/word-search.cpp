class Solution {
public:
    int n;
    int m;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool getAns(vector<vector<char>> &board, string word, int idx, int i, int j){
        if(idx == word.size()){
            cout << i << " " << j << endl;
            return true;
        }
        for(int a = 0; a < 4; a++){
            int nx = i + dx[a];
            int ny = j + dy[a];
            if(nx < n && nx >= 0 && ny < m && ny >= 0 && board[nx][ny] == word[idx]){
                char temp = board[nx][ny];
                board[nx][ny] = '.';
                bool ans = getAns(board, word, idx + 1, nx, ny);
                board[nx][ny] = temp;
                if(ans) return true;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        if(word.size() > n * m) return false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0] && getAns(board, word, 1, i, j)){
                    char temp = board[i][j];
                    board[i][j] = '.';
                    bool ans = getAns(board, word, 1, i, j);
                    board[i][j] = temp;
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};