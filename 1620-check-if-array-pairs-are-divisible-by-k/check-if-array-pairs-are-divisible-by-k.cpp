class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> check(k);
        for(int i = 0; i < n; i++){
            check[((arr[i] % k) + k) % k].push_back(arr[i]);
        }

        if(check[0].size() % 2 != 0){
            return false;
        }
        
        for(int i = 1; i <= k/2 ; i++){
            if(k%2 == 0 && i == k/2){
                if(check[i].size() % 2 != 0){
                    return false;
                }
                continue;
            }
            if(check[i].size() != check[k-i].size()){
                return false;
            }
        }
        return true;
    }
};