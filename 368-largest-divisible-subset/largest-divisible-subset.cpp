class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        sort(nums.begin(), nums.end());
        int mx = 1;
        int best_idx = 0;
        for(int i = 1; i < n; i++){
            int ans = 0;
            int ans_idx = -1;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[j] > ans){
                        ans = dp[j];
                        ans_idx = j;
                    }
                }
            }
            prev[i] = ans_idx;
            dp[i] = ans + 1;
            
            if(dp[i] > mx){
                mx = dp[i];
                best_idx = i;
            }
        }
        vector<int> result;
        while(best_idx != -1){
            result.push_back(nums[best_idx]);
            best_idx = prev[best_idx];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};