class Spreadsheet {
public:
    vector<vector<int>> check;
    Spreadsheet(int rows) {
        check.resize(rows + 1, vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        check[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        check[row][col] = 0;
    }
    
    int getValue(string formula) {
        int n = formula.size();
        int i = 1;
        int sum = 0;
        int col;
        while(i < n){
            col = -1;
            if(formula[i] >= 'A' && formula[i] <= 'Z'){
                col = formula[i] - 'A';
                i++;
            }
            int row = 0;
            while(i < n && formula[i] != '+'){
                row = (row * 10) + (int)(formula[i] - '0');
                i++; 
            }
            i++;
            if(col == -1){
                sum += row;
            }else{
                sum += check[row][col];
            }
        }
        return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */