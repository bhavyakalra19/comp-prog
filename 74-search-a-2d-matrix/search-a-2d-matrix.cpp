class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int st = 0;
        int en = n*m - 1;
        while(st <= en){
            int mid = st + (en - st)/2;
            int i = mid / m;
            int j = mid % m;
            if(target == matrix[i][j]){
                return true;
            }else if(target < matrix[i][j]){
                en = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return false;
    }
};
