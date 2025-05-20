class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> check(n+1, 0);
        for(auto q : queries){
            check[q[0]]--;
            check[q[1] + 1]++;
        }
        int a = 0;
        for(int i = 0; i < n; i++){
            a += check[i];
            if(a + nums[i] > 0) return false;
        }
        return true;
    }
};