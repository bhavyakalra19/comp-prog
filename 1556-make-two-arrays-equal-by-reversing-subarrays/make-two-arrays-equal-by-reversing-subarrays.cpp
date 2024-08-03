class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        vector<int> check(1001,0);
        for(int i = 0; i < n; i++){
            check[target[i]] += 1;
        }
        for(int i = 0; i < n; i++){
            if(check[arr[i]] == 0){
                return false;
            }
            check[arr[i]] -= 1;
        }
        return true;
    }
};