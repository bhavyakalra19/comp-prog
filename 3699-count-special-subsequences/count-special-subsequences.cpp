class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        unordered_map<double,int> mp;
        for(int i = 0; i < n - 3; i++){
            for(int j = i+2; j < n - 3; j++){
                mp[(double)nums[i]/(double)nums[j]]++;
            }
        }
        long long ans = 0;
        for(int i = n - 3; i >= 4; i--){
            for(int j = 0; j < i - 2; j++){
                mp[(double)nums[j]/(double)nums[i-1]]--;
            }
            for(int j = i+2; j < n; j++){
                ans += mp[(double)nums[j]/(double)nums[i]];
            }
        }
        return ans;
    }
};


