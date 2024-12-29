class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        unordered_map<double,int> mp;
        long long ans = 0;
        for(int i = 0; i < n - 6; i++){
            for(int j = i+2; j < n - 4; j++){
                mp[(double) nums[i] /nums[j]]++;
            }
        }

        for(int i = n - 3; i >= 4; i--){
            for(int j = i+2; j < n; j++){
                ans += mp[(double) nums[j] /nums[i]];
            }
            for(int j = 0; j <= i - 4; j++){
                mp[(double) nums[j] /nums[i-2]]--;
            }
        }
        return ans;
    }
};