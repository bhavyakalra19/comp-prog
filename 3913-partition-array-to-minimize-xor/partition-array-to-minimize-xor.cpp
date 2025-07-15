class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> check(n+1, 0);
        for(int i = 1; i <= n; i++){
            check[i] = check[i-1] ^ nums[i-1];
        }
        vector<vector<int>> prev(n, vector<int>(k+1, INT_MAX));
        vector<vector<int>> curr(n, vector<int>(k+1, INT_MAX));
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                for(int a = 1; a <= k; a++){
                    if((n - i) < a){
                        curr[j][a] = INT_MAX;
                    }else if(a == 1){
                        curr[j][a] = check[n] ^ check[i];
                    }else{
                        int b = prev[j][a];
                        b = min(b, max(check[i+1] ^ check[j],prev[i+1][a-1]));
                        curr[j][a] = b;
                    }
                }
            }
            prev = curr;
        }
        return prev[0][k];
    }
};