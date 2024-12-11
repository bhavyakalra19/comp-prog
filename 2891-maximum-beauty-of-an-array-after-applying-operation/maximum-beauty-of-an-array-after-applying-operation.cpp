class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> check(100003, 0);
        for(auto a : nums){
            int mn = max(0,a-k);
            int mx = min(100002, a+k+1);
            check[mn] += 1;
            check[mx] -= 1;
        }
        int ans = 0;
        int sm = 0;
        for(auto c : check){
            sm += c;
            ans = max(ans,sm);
        }
        return ans;
    }
};
