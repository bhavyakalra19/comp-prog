class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int arr[100001] = {0};
        long long sum = 0;
        int count = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            arr[nums[i]] += 1;
            if(arr[nums[i]] == 2){
                count += 1;
            }
            if(i >= k - 1){
                if(count == 0){
                   ans = max(ans,sum); 
                }
                sum -= nums[i - k + 1];
                arr[nums[i-k+1]]--;
                if(arr[nums[i-k+1]] == 1){
                    count -= 1;
                }
            }
        }
        return ans;
    }
};