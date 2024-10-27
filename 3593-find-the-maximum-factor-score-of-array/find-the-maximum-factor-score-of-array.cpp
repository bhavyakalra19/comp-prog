class Solution {
public:
    long long getAns(vector<int> nums, int x){
        int n = nums.size();
        long long hcf = (x == 0) ? nums[1] : nums[0];
        long long lcm = hcf;
        for(int i = (x == 0 ? 2 : 1); i < n; i++){
            if(i != x){
                lcm = (lcm * nums[i]) / gcd(lcm,nums[i]);
                hcf = gcd(hcf,nums[i]);
            }
        }
        return lcm * hcf;
    }

    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        if(n == 1){
            return (long long) nums[0] * nums[0];
        }
        for(int i = -1; i < n; i++){
            ans = max(ans,getAns(nums,i));
        }
        return ans;
    }
};