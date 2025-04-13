class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mn = INT_MAX;
        int mnSum = INT_MAX;
        for(int i = 0; i < n-2; i++){
            int j = i+1;
            int k = n-1;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target - sum) < mnSum){
                    mn = sum;
                    mnSum = abs(target - sum);
                }
                if(sum >= target){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return mn;
    }
};