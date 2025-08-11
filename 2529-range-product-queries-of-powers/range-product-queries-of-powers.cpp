class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> nums;
        vector<int> ans;
        int cnt = 0;
        while(n > 0){
            if(n & 1) nums.push_back(cnt);
            cnt++;
            n >>= 1;
        }
        vector<int> check(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            check[i+1] = check[i] + nums[i];
        }
        for(auto &q : queries){
            int a = check[q[1] + 1] - check[q[0]];
            int curr = 1;
            long long b = 2;
            while(a > 0){
               if(a & 1){
                    curr = (curr * b) % mod; 
               }
               a >>= 1;
               b = (b * b) % mod;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};