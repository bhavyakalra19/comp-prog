class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            nums[i] = gcd(mx, nums[i]);
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n-1;
        long long sum = 0;
        while(i < j){
            sum += gcd(nums[i], nums[j]);
            i++;
            j--;
        }
        return sum;
    }
};