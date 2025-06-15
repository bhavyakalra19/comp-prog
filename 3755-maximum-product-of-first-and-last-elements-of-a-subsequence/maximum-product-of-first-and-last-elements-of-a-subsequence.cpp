class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        stack<int> mx;
        stack<int> mn;
        for(int i = n-1; i >= m-1; i--){
            if(mx.empty() || nums[i] > nums[mx.top()]){
                mx.push(i);
            }
            if(mn.empty() || nums[i] < nums[mn.top()]){
                mn.push(i);
            }
        }
        long long ans = LONG_MIN;
        int j = m-1;
        for(int i = 0; i <= n - m; i++){
            if(nums[i] <= 0){
                ans = max(ans, 1LL * nums[i] * nums[mn.top()]);
            }else{
                ans = max(ans, 1LL * nums[i] * nums[mx.top()]);
            }
            if(mn.top() == j){
                mn.pop();
            }
            if(mx.top() == j){
                mx.pop();
            }
            j++;
        }
        return ans;
    }
};
// sliding window
// 2 stacks
// neg -> neg; pos -> pos