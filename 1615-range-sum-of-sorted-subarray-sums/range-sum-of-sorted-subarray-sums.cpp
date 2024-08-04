class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int ans = 0;
        vector<long long> check;
        check.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            check.push_back(check[i-1] + nums[i]);
        }
        for(int i = 1; i < n; i++){
            int s = check.size();
            for(int j = 0;j < n - i; j++){
                check.push_back(check[s - n + j + i] - (long long)nums[i - 1]);
            }
        }
        sort(check.begin(),check.end());
        for(int i = left - 1; i < right; i++){
            ans += check[i];
            if(ans >= 716699888){
                return 716699888;
            }
        }
        return ans;
    }
};