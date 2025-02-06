class Solution {
public:
    vector<int> getRow(int n) {
        n += 1;
        if(n == 1) return {1};
        if(n == 2) return {1,1};
        vector<int> check{1,1};
        for(int i = 2; i < n; i++){
            vector<int> curr;
            curr.push_back(1);
            for(int j = 1; j < check.size(); j++){
                curr.push_back(check[j] + check[j-1]);
            }
            curr.push_back(1);
            check = curr;
        }
        return check;
    }
};