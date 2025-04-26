class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n, 1);
        int mx = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && check[j] + 1 > check[i]){
                    check[i] = check[j] + 1;
                }
            }
            mx = max(mx, check[i]);
        }
        return mx;
    }
};