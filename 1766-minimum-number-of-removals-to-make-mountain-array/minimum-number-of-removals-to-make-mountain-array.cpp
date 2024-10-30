class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        int ans = 0;
        for(int i = 1; i < n; i++){
            int ans = 0;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && left[j] > ans){
                    ans = left[j];
                }
            }
            ans += 1;
            left[i] = ans;
        }
        for(int i = n - 2; i >= 0; i--){
            int ans = 0;
            for(int j = n - 1; j > i; j--){
                if(nums[i] > nums[j] && ans < right[j]){
                    ans = right[j];
                }
            }
            ans += 1;
            right[i] = ans;
        }
        for(int i = 1; i < n - 1; i++){
            if(left[i] > 1 && right[i] > 1){
                ans = max(ans, left[i] + right[i] - 1);
            }
        }
        return n - ans;
    }
};