class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = -1;
        if(k == 1){
            return true;
        }
        vector<int> check;
        check.push_back(1);
        int t = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                t += 1;
            }else{
                t = 1;
            }
            check.push_back(t);
            if(i - k > 0 && check[i] >= k && check[i-k] >= k){
                return true;
            }
        }
        return false;
    }
};