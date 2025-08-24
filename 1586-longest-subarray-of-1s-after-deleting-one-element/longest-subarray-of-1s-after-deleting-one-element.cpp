class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zc = 0;
        int one = -1;
        int two = -1;
        int three = -1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                one = two;
                two = three;
                three = i;
                ans = max(ans, three - one - 2);
            }else{
                ans = max(ans, i - two - 1);
            }
        }
        if(two == -1){
            return n - 1;
        }
        return ans;
    }
};