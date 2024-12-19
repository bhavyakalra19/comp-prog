class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        sum /= 2;
        vector<int> prev(sum+1,0);
        if(nums[0] <= sum) prev[nums[0]] = 1;
        for(int i = 1; i < n; i++){
            vector<int> curr(sum+1,0);
            prev[0] = 1;
            for(int j = 0; j <= sum; j++){
                bool a = prev[j];
                bool b = false;
                if(nums[i] <= j) b = prev[j - nums[i]];
                curr[j] = a | b;
            }
            prev = curr;
        }
        return prev[sum];
    }
};