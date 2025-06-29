class Solution {
public:
    int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int i = 0;
        int j = n-1;
        vector<int> powers(n);
        powers[0] = 1;
        for(int i = 1; i < n; i++){
            powers[i] = (powers[i-1] * 2) % mod;
        }
        while(i <= j){
            while(i <= j && nums[i] + nums[j] > target){
                j--;
            }
            if(i > j) break;
            ans = (ans + powers[j - i]) % mod; 
            i++;
        }
        return ans;
    }
};