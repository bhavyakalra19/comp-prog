class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
       int total = 0;
       int mx = 0;
       vector<int> ans;
       for(int i = 0; i < 3; i++){
            int a = nums[i];
            int c = 0;
            while(a > 0){
                a = a >> 1;
                c += 1;
            }
            ans.push_back(c);
            total += c;
        }
        int a = max((nums[0] << (total - ans[0])) + (nums[1] << (total - ans[0] - ans[1])) + nums[2], (nums[0] << (total - ans[0])) + (nums[2] << (total - ans[0] - ans[2])) + nums[1]);
        int b = max((nums[1] << (total - ans[1])) + (nums[0] << (total - ans[0] - ans[1])) + nums[2], (nums[1] << (total - ans[1])) + (nums[2] << (total - ans[1] - ans[2])) + nums[0]);
        mx = max(a,b);
        int c = max((nums[2] << (total - ans[2])) + (nums[0] << (total - ans[2] - ans[0])) + nums[1], (nums[2] << (total - ans[2])) + (nums[1] << (total - ans[1] - ans[2])) + nums[0]);
        return max(mx,c);
    }
};