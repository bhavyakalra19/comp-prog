class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        int check = 0;
        int mx = 1;
        vector<int> mp(n);
        mp[0] = 0;
        for(int i = 1; i < n; i++){
            mp[i] = i;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    mp[i] = j;
                    if(dp[i] > mx){
                        mx = dp[i];
                        check = i;
                    }
                }
            }
        }

        vector<int> ans;
        ans.push_back(nums[check]);
        while(check != mp[check]){
            check = mp[check];
            ans.push_back(nums[check]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};